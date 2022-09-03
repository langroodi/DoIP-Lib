#include "doiplib/message.h"
#include "doiplib/convert.h"

namespace DoipLib
{
    const std::size_t Message::cHeaderSize;

    Message::Message(
        uint8_t protocolVersion,
        PayloadType payloadType) noexcept : mProtocolVersion{protocolVersion},
                                            mPayloadType{payloadType}
    {
    }

    void Message::Serialize(std::vector<uint8_t> &serializedMessage)
    {
        GetPayload(serializedMessage);

        auto _payloadLength{static_cast<uint32_t>(serializedMessage.size())};
        Convert::ToByteArray<uint32_t>(_payloadLength, serializedMessage);

        auto _payloadTypeInt{static_cast<uint16_t>(mPayloadType)};
        Convert::ToByteArray<uint16_t>(_payloadTypeInt, serializedMessage);

        auto _inverseProtocolVersion{static_cast<uint8_t>(~mProtocolVersion)};
        serializedMessage.insert(serializedMessage.begin(), _inverseProtocolVersion);

        serializedMessage.insert(serializedMessage.begin(), mProtocolVersion);
    }

    bool Message::TryDeserialize(const std::vector<uint8_t> &serializedMessage)
    {
        // Header length check
        if (serializedMessage.size() < cHeaderSize)
        {
            return false;
        }

        std::size_t _offset{0};
        uint8_t _actualProtocolVersion{serializedMessage.at(_offset)};
        ++_offset;

        uint8_t _inverseProtocolVersion{serializedMessage.at(_offset)};
        ++_offset;

        // Protocol version check
        auto _expectedProtocolVersion{
            static_cast<uint8_t>(~_inverseProtocolVersion)};

        if (_actualProtocolVersion != _expectedProtocolVersion)
        {
            return false;
        }

        auto _payloadTypeInt{
            Convert::ToUnsignedInteger<uint16_t>(serializedMessage, _offset)};
        auto _payloadType{static_cast<PayloadType>(_payloadTypeInt)};

        auto _payloadLength{
            Convert::ToUnsignedInteger<uint32_t>(serializedMessage, _offset)};

        // Payload length check
        if (_payloadLength != serializedMessage.size() - cHeaderSize)
        {
            return false;
        }

        bool _succeed{TrySetPayload(serializedMessage)};
        if (_succeed)
        {
            mProtocolVersion = _actualProtocolVersion;
            mPayloadType = _payloadType;
        }

        return _succeed;
    }

    bool Message::TryExtractPayloadType(
        const std::vector<uint8_t> &serializedMessage,
        PayloadType &payloadType)
    {
        if (serializedMessage.size() >= cHeaderSize)
        {
            std::size_t cPayloadOffset{2};

            auto _payloadTypeInt{
                Convert::ToUnsignedInteger<uint16_t>(
                    serializedMessage, cPayloadOffset)};
            payloadType = static_cast<PayloadType>(_payloadTypeInt);

            return true;
        }
        else
        {
            return false;
        }
    }
}