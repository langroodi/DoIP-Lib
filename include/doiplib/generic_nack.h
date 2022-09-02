#ifndef GENERIC_NACK_H
#define GENERIC_NACK_H

#include "./message.h"
#include "./nack_type.h"

namespace DoipLib
{
    class GenericNack : public Message
    {
    private:
        static const PayloadType cPayloadType{
            PayloadType::GenericNegativeAcknowledgement};

        NackType mNackCode;

    protected:
         void GetPayload(std::vector<uint8_t> &payload) override;

         virtual bool TrySetPayload(const std::vector<uint8_t> &payload) override;
         
    public:
        GenericNack() noexcept = default;
        
        /// @brief Constructor
        /// @param protocolVersion DoIP ISO protocol version
        /// @param nackCode Negative acknowledgement code
        GenericNack(uint16_t protocolVersion, NackType nackCode) noexcept;

        /// @brief Get NACK code
        /// @return Negative acknoweledgement code
        NackType GetNackCode() const noexcept;
    };
}

#endif