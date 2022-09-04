#include <stdexcept>
#include <utility>
#include "doiplib/vin_vehicle_id_request.h"

namespace DoipLib
{
    const PayloadType VinVehicleIdRequest::cPayloadType;
    const std::size_t VinVehicleIdRequest::cVinSize;

    VinVehicleIdRequest::VinVehicleIdRequest() noexcept : Message(cPayloadType)
    {
    }

    VinVehicleIdRequest::VinVehicleIdRequest(
        uint16_t protocolVersion, std::string vin) : Message(protocolVersion, cPayloadType),
                                                     mVin{vin.size() == cVinSize ? vin : throw std::out_of_range("Invalid vehicle ID number")}
    {
    }

    VinVehicleIdRequest::VinVehicleIdRequest(
        uint16_t protocolVersion, std::string &&vin) : Message(protocolVersion, cPayloadType),
                                                       mVin{vin.size() == cVinSize ? std::move(vin) : throw std::out_of_range("Invalid vehicle ID number")}
    {
    }

    void VinVehicleIdRequest::GetPayload(std::vector<uint8_t> &payload)
    {
        payload = std::vector<uint8_t>(mVin.cbegin(), mVin.cend());
    }

    bool VinVehicleIdRequest::TrySetPayload(const std::vector<uint8_t> &payload)
    {
        const std::size_t cExpectedSize{
            static_cast<std::size_t>(cHeaderSize + cVinSize)};

        if (payload.size() == cExpectedSize)
        {
            auto _beginItr{payload.cbegin() + cHeaderSize};

            mVin = std::string(_beginItr, payload.cend());

            return true;
        }
        else
        {
            return false;
        }
    }

    std::string VinVehicleIdRequest::GetVin() const
    {
        return mVin;
    }
}