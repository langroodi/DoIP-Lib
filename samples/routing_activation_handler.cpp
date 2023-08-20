#include <utility>
#include "./routing_activation_handler.h"

namespace DoipLib
{
    const uint8_t RoutingActivationHandler::cSupportedActivationType;
    const bool RoutingActivationHandler::cHasOemSpecificData;

    RoutingActivationHandler::RoutingActivationHandler(
        uint8_t protocolVersion,
        uint16_t logicalAddress) : cProtocolVersion{protocolVersion}, cLogicalAddress{logicalAddress}
    {
    }

    Message *RoutingActivationHandler::GetMessage()
    {
        return static_cast<Message *>(&mRequest);
    }

    bool RoutingActivationHandler::TryHandle(
        const Message *request, std::vector<uint8_t> &response) const
    {
        auto _routingActivationRequest{
            dynamic_cast<const RoutingActivationRequest *>(request)};

        if (_routingActivationRequest == nullptr)
        {
            return false;
        }

        const uint16_t cTesterAddress{_routingActivationRequest->GetSourceAddress()};
        RoutingActivationResponseType _responseCode;

        if (_routingActivationRequest->GetActivationType() != cSupportedActivationType)
        {
            _responseCode = RoutingActivationResponseType::UnsupportedActivationType;
        }
        else if (mActiveTesters.find(cTesterAddress) != mActiveTesters.end())
        {
            _responseCode = RoutingActivationResponseType::AlreadyRegisteredTester;
        }
        else
        {
            mActiveTesters.emplace(cTesterAddress);
            _responseCode = RoutingActivationResponseType::Successful;
        }
        
        RoutingActivationResponse _routingActivationResponse(
            cProtocolVersion,
            cTesterAddress,
            cLogicalAddress,
            _responseCode);

        _routingActivationResponse.Serialize(response);

        return true;
    }
}