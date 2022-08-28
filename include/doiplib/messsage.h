#ifndef MESSAGE_H
#define MESSAGE_H

#include <vector>
#include "./payload_type.h"

namespace DoipLib
{
    /// @brief DoIP generic message
    class Message
    {
    private:
        uint8_t mProtocolVersion;
        PayloadType mPayloadType;

    protected:
        /// @brief Constructor
        /// @param protocolVersion DoIP ISO protocol version
        /// @param payloadType DoIP message payload type
        Message(uint8_t protocolVersion, PayloadType payloadType);

        /// @brief Get message payload
        /// @param[out] payload Payload byte array
        virtual void GetPayload(std::vector<uint8_t> &payload) = 0;

        /// @brief Set message payload
        /// @param[in] payload Payload byte array
        virtual void SetPayload(const std::vector<uint8_t> &payload) = 0;

    public:
        /// @brief Serialize DoIP message
        /// @param[out] serializedMessage Serialize message byte array
        void Serialize(std::vector<uint8_t> &serializedMessage);

        /// @brief Deserialize DoIP message
        /// @param[in] serializedMessage Serialize message byte array
        void Deserialize(const std::vector<uint8_t> &serializedMessage);
    };
}

#endif