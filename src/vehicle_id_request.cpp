#include "doiplib/vehicle_id_request.h"

namespace DoipLib
{
    const PayloadType VehicleIdRequest::cPayloadType;

    VehicleIdRequest::VehicleIdRequest(
        uint16_t protocolVersion) noexcept : Message(protocolVersion, cPayloadType)
    {
    }

    void VehicleIdRequest::GetPayload(std::vector<uint8_t> &payload)
    {
        // The message contain no payload.
    }

    bool VehicleIdRequest::TrySetPayload(
        const std::vector<uint8_t> &payload, PayloadType payloadType)
    {
        // The message contain no payload.
        return (payloadType == cPayloadType);
    }
}