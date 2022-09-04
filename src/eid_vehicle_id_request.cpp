#include <algorithm>
#include <utility>
#include "doiplib/eid_vehicle_id_request.h"

namespace DoipLib
{
    const PayloadType EidVehicleIdRequest::cPayloadType;
    const std::size_t EidVehicleIdRequest::cEidSize;

    EidVehicleIdRequest::EidVehicleIdRequest() noexcept : Message(cPayloadType)
    {
    }

    EidVehicleIdRequest::EidVehicleIdRequest(
        uint16_t protocolVersion,
        std::array<uint8_t, cEidSize> eid) : Message(protocolVersion, cPayloadType),
                                             mEid{eid}
    {
    }

    EidVehicleIdRequest::EidVehicleIdRequest(
        uint16_t protocolVersion,
        std::array<uint8_t, cEidSize> &&eid) : Message(protocolVersion, cPayloadType),
                                               mEid{std::move(eid)}
    {
    }

    void EidVehicleIdRequest::GetPayload(std::vector<uint8_t> &payload)
    {
        payload = std::vector<uint8_t>(mEid.cbegin(), mEid.cend());
    }

    bool EidVehicleIdRequest::TrySetPayload(const std::vector<uint8_t> &payload)
    {
        const std::size_t cExpectedSize{
            static_cast<std::size_t>(cHeaderSize + cEidSize)};

        if (payload.size() == cExpectedSize)
        {
            auto _beginItr{payload.cbegin() + cHeaderSize};
            std::copy_n(_beginItr, cEidSize, mEid.begin());

            return true;
        }
        else
        {
            return false;
        }
    }

    std::array<uint8_t, EidVehicleIdRequest::cEidSize> EidVehicleIdRequest::GetEid() const
    {
        return mEid;
    }
}