#ifndef VEHICLE_ID_REQUEST_H
#define VEHICLE_ID_REQUEST_H

#include "./message.h"

namespace DoipLib
{
    /// @brief Vehicle ID request DoIP message
    class VehicleIdRequest : public Message
    {
    private:
        static const PayloadType cPayloadType{
            PayloadType::VehicleIdRequest};

    protected:
         void GetPayload(std::vector<uint8_t> &payload) override;

         virtual bool TrySetPayload(
            const std::vector<uint8_t> &payload, PayloadType payloadType) override;
         
    public:
        VehicleIdRequest() noexcept = default;
        
        /// @brief Constructor
        /// @param protocolVersion DoIP ISO protocol version
        VehicleIdRequest(uint16_t protocolVersion) noexcept;
    };
}

#endif