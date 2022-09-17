#include <iterator>
#include <algorithm>
#include <utility>
#include <gtest/gtest.h>
#include <doiplib/diag_message_ack.h>

namespace DoipLib
{
    TEST(DiagMessageAckTest, SerializationWithoutPreviousMessage)
    {
        const uint8_t cProtocolVersion{0x02};
        const uint16_t cSourceAddress{0x0001};
        const uint16_t cTargetAddress{0x0002};
        const std::size_t cPayloadLength{13};
        const std::array<uint8_t, cPayloadLength> cExpectedResult{
            0x02, 0xfd, 0x80, 0x02, 0x00, 0x00, 0x00, 0x05,
            0x00, 0x01, 0x00, 0x02, 0x00};

        DiagMessageAck _message(
            cProtocolVersion, cSourceAddress, cTargetAddress);
        std::vector<uint8_t> _actualResult;
        _message.Serialize(_actualResult);

        bool _areEqual =
            std::equal(
                std::cbegin(cExpectedResult),
                std::cend(cExpectedResult),
                std::cbegin(_actualResult));
        EXPECT_TRUE(_areEqual);
    }

    TEST(DiagMessageAckTest, SerializationCopyingPreviousMessage)
    {
        const uint8_t cProtocolVersion{0x02};
        const uint16_t cSourceAddress{0x0001};
        const uint16_t cTargetAddress{0x0002};
        const std::vector<uint8_t> cPreviousMessage{0xab, 0xcd, 0xef};
        const std::size_t cPayloadLength{16};
        const std::array<uint8_t, cPayloadLength> cExpectedResult{
            0x02, 0xfd, 0x80, 0x02, 0x00, 0x00, 0x00, 0x08,
            0x00, 0x01, 0x00, 0x02, 0x00, 0xab, 0xcd, 0xef};

        DiagMessageAck _message(
            cProtocolVersion, cSourceAddress, cTargetAddress, cPreviousMessage);
        std::vector<uint8_t> _actualResult;
        _message.Serialize(_actualResult);

        bool _areEqual =
            std::equal(
                std::cbegin(cExpectedResult),
                std::cend(cExpectedResult),
                std::cbegin(_actualResult));
        EXPECT_TRUE(_areEqual);
    }

    TEST(DiagMessageAckTest, SerializationMovingPreviousMessage)
    {
        const uint8_t cProtocolVersion{0x02};
        const uint16_t cSourceAddress{0x0001};
        const uint16_t cTargetAddress{0x0002};
        std::vector<uint8_t> _previousMessage{0xab, 0xcd, 0xef};
        const std::size_t cPayloadLength{16};
        const std::array<uint8_t, cPayloadLength> cExpectedResult{
            0x02, 0xfd, 0x80, 0x02, 0x00, 0x00, 0x00, 0x08,
            0x00, 0x01, 0x00, 0x02, 0x00, 0xab, 0xcd, 0xef};

        DiagMessageAck _message(
            cProtocolVersion, cSourceAddress, cTargetAddress, std::move(_previousMessage));
        std::vector<uint8_t> _actualResult;
        _message.Serialize(_actualResult);

        bool _areEqual =
            std::equal(
                std::cbegin(cExpectedResult),
                std::cend(cExpectedResult),
                std::cbegin(_actualResult));
        EXPECT_TRUE(_areEqual);
    }

    TEST(DiagMessageAckTest, ValidDeserializationWithoutPreviousMessage)
    {
        const uint16_t cSourceAddress{0x0001};
        const uint16_t cTargetAddress{0x0002};
        const std::vector<uint8_t> cSerializedMessage{
            0x02, 0xfd, 0x80, 0x02, 0x00, 0x00, 0x00, 0x05,
            0x00, 0x01, 0x00, 0x02, 0x00};

        DiagMessageAck _message;
        bool _succeed{_message.TryDeserialize(cSerializedMessage)};
        EXPECT_TRUE(_succeed);

        EXPECT_EQ(cSourceAddress, _message.GetSourceAddress());
        EXPECT_EQ(cTargetAddress, _message.GetTargetAddress());
    }

    TEST(DiagMessageAckTest, ValidDeserializationUsingPreviousMessage)
    {
        const std::vector<uint8_t> cExpectedResult{0xab, 0xcd, 0xef};
        const std::vector<uint8_t> cSerializedMessage{
            0x02, 0xfd, 0x80, 0x02, 0x00, 0x00, 0x00, 0x08,
            0x00, 0x01, 0x00, 0x02, 0x00, 0xab, 0xcd, 0xef};

        DiagMessageAck _message;
        bool _succeed{_message.TryDeserialize(cSerializedMessage)};
        EXPECT_TRUE(_succeed);

        std::vector<uint8_t> _actualResult;
        _succeed = {_message.TryGetPreviousMessage(_actualResult)};
        EXPECT_TRUE(_succeed);
        EXPECT_EQ(cExpectedResult, _actualResult);
    }

    TEST(DiagMessageAckTest, InvalidSizeDeserialization)
    {
        const std::vector<uint8_t> cSerializedMessage{
            0x02, 0xfd, 0x80, 0x02, 0x00, 0x00, 0x00, 0x00};

        DiagMessageAck _message;
        bool _succeed{_message.TryDeserialize(cSerializedMessage)};
        EXPECT_FALSE(_succeed);
    }

    TEST(DiagMessageAckTest, InvalidDeserializationWithoutPreviousMessage)
    {
        const std::vector<uint8_t> cSerializedMessage{
            0x02, 0xfd, 0x80, 0x02, 0x00, 0x00, 0x00, 0x05,
            0x00, 0x01, 0x00, 0x02, 0xff};

        DiagMessageAck _message;
        bool _succeed{_message.TryDeserialize(cSerializedMessage)};
        EXPECT_FALSE(_succeed);
    }

    TEST(DiagMessageAckTest, InvalidDeserializationUsingPreviousMessage)
    {
        const std::vector<uint8_t> cSerializedMessage{
            0x02, 0xfd, 0x80, 0x02, 0x00, 0x00, 0x00, 0x08,
            0x00, 0x01, 0x00, 0x02, 0xff, 0xab, 0xcd, 0xef};

        DiagMessageAck _message;
        bool _succeed{_message.TryDeserialize(cSerializedMessage)};
        EXPECT_FALSE(_succeed);
    }
}