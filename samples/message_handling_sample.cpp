#include <utility>
#include <iostream>
#include "./vehicle_id_message_handler.h"
#include "./routing_activation_handler.h"
#include "../include/doiplib/doip_controller.h"

constexpr std::size_t cIdSize{6};
const uint8_t cProtocolVersion{0x02};
const std::array<uint8_t, cIdSize> cEid{0xaa, 0xbb, 0xcc, 0xdd, 0xee, 0xff};
// Use EID as GID
const std::array<uint8_t, cIdSize> cGid{cEid};

bool handleMessage(
    const DoipLib::DoipController &doipController,
    const DoipLib::Message &request,
    DoipLib::Message &response)
{
    std::vector<uint8_t> _serializedRequest;
    request.Serialize(_serializedRequest);

    std::vector<uint8_t> _serializedResponse;

    bool _isHandled{
        doipController.TryHandle(_serializedRequest, _serializedResponse)};

    if (_isHandled)
    {
        DoipLib::GenericNackType _nackCode;
        bool _isDeserialized{
            response.TryDeserialize(_serializedResponse, _nackCode)};

        if (_isDeserialized)
        {
            return true;
        }
        else
        {
            std::cout << "Response is NOT deserialized correctly!\n";
        }
    }
    else
    {
        std::cout << "Request is NOT handled correctly!\n";
    }

    return false;
}

void handleVehicleIdMessage(const DoipLib::DoipController &doipController)
{
    const std::array<uint8_t, cIdSize> cInvalidEid{
        0xa0, 0xb0, 0xc0, 0xd0, 0xe0, 0xf0};

    DoipLib::VehicleIdResponse _response;

    const DoipLib::EidVehicleIdRequest cValidRequest(
        cProtocolVersion, cEid);

    if (handleMessage(doipController, cValidRequest, _response))
    {
        std::cout << "VIN: " << _response.GetVin() << std::endl
                  << "LogicalAddress: " << _response.GetLogicalAddress() << std::endl;
    }

    const DoipLib::EidVehicleIdRequest cInvalidRequest(
        cProtocolVersion, cInvalidEid);

    handleMessage(doipController, cInvalidRequest, _response);
}

void printResponseCode(DoipLib::RoutingActivationResponseType responseCode)
{
    switch (responseCode)
    {
    case DoipLib::RoutingActivationResponseType::Successful:
        std::cout << "Routing is activated successfully." << std::endl;
        break;

    case DoipLib::RoutingActivationResponseType::AlreadyRegisteredTester:
        std::cout << "Tester is already registered." << std::endl;
        break;

    case DoipLib::RoutingActivationResponseType::UnsupportedActivationType:
        std::cout << "Activation type is not supported." << std::endl;
        break;

    default:
        std::cout << "Response code is out of range." << std::endl;
        break;
    }
}

void handleRoutingActivation(const DoipLib::DoipController &doipController)
{
    const uint16_t cTesterAddress{0x0002};
    const uint8_t cDefaultActivation{0x00};
    const uint8_t cWwhObdActivation{0x01};

    DoipLib::RoutingActivationResponse _response;

    DoipLib::RoutingActivationRequest cDefaultRequest(
        cProtocolVersion, cTesterAddress, cDefaultActivation);
    if (handleMessage(doipController, cDefaultRequest, _response))
    {
        printResponseCode(_response.GetResponseCode());
    }

    if (handleMessage(doipController, cDefaultRequest, _response))
    {
        printResponseCode(_response.GetResponseCode());
    }
    
    DoipLib::RoutingActivationRequest cWwhObdRequest(
        cProtocolVersion, cTesterAddress, cWwhObdActivation);
    if (handleMessage(doipController, cWwhObdRequest, _response))
    {
        printResponseCode(_response.GetResponseCode());
    }
}

int main()
{
    const uint16_t cLogicalAddress{0x0001};

    DoipLib::ControllerConfig _config;
    _config.protocolVersion = cProtocolVersion;
    _config.doipMaxRequestBytes = 64;
    _config.doIPInitialVehicleAnnouncementTime = std::chrono::seconds(0);
    _config.doIPVehicleAnnouncementCount = 3;
    _config.doIPVehicleAnnouncementInterval = std::chrono::seconds(1);

    DoipLib::DoipController _doipController(std::move(_config));

    DoipLib::VehicleIdMessageHandler _vehicleIdMessageHandler(
        _config.protocolVersion,
        "ABCDEFGHIJKLMNOPQ",
        cLogicalAddress,
        cEid,
        cGid);

    _doipController.Register(
        DoipLib::PayloadType::VehicleIdRequestWithEid, &_vehicleIdMessageHandler);

    DoipLib::RoutingActivationHandler _routingActivationHandler(
        _config.protocolVersion,
        cLogicalAddress);

    _doipController.Register(
        DoipLib::PayloadType::RoutingActivationRequest, &_routingActivationHandler);

    handleVehicleIdMessage(_doipController);
    handleRoutingActivation(_doipController);

    return 0;
}