#include <iterator>
#include <algorithm>
#include <gtest/gtest.h>
#include <doiplib/routing_activation_request.h>

namespace DoipLib
{
    TEST(RoutingActivationRequestTest, SerializationWithoutOemData)
    {
        const uint8_t cProtocolVersion{0x02};
        const uint16_t cSourceAddress{0x0001};
        const uint8_t cActivationType{0xe0};
        const std::size_t cPayloadLength{15};
        const std::array<uint8_t, cPayloadLength> cExpectedResult{
            0x02, 0xfd, 0x00, 0x05, 0x00, 0x00, 0x00, 0x07,
            0x00, 0x01, 0xe0, 0x00, 0x00, 0x00, 0x00};

        RoutingActivationRequest _message(
            cProtocolVersion, cSourceAddress, cActivationType);
        std::vector<uint8_t> _actualResult;
        _message.Serialize(_actualResult);

        bool _areEqual =
            std::equal(
                std::cbegin(cExpectedResult),
                std::cend(cExpectedResult),
                std::cbegin(_actualResult));
        EXPECT_TRUE(_areEqual);
    }

    TEST(RoutingActivationRequestTest, SerializationUsingOemData)
    {
        const uint8_t cProtocolVersion{0x02};
        const uint16_t cSourceAddress{0x0001};
        const uint8_t cActivationType{0xe0};
        const uint32_t cOemSpecificData{0x12345678};
        const std::size_t cPayloadLength{19};
        const std::array<uint8_t, cPayloadLength> cExpectedResult{
            0x02, 0xfd, 0x00, 0x05, 0x00, 0x00, 0x00, 0x0b,
            0x00, 0x01, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x12, 0x34, 0x56, 0x78};

        RoutingActivationRequest _message(
            cProtocolVersion, cSourceAddress, cActivationType, cOemSpecificData);
        std::vector<uint8_t> _actualResult;
        _message.Serialize(_actualResult);

        bool _areEqual =
            std::equal(
                std::cbegin(cExpectedResult),
                std::cend(cExpectedResult),
                std::cbegin(_actualResult));
        EXPECT_TRUE(_areEqual);
    }

    TEST(RoutingActivationRequestTest, DeserializationWithoutOemData)
    {
        const uint16_t cSourceAddress{0x0001};
        const uint8_t cActivationType{0xe0};
        const std::vector<uint8_t> cSerializedMessage{
            0x02, 0xfd, 0x00, 0x05, 0x00, 0x00, 0x00, 0x07,
            0x00, 0x01, 0xe0, 0x00, 0x00, 0x00, 0x00};

        RoutingActivationRequest _message;
        bool _succeed{_message.TryDeserialize(cSerializedMessage)};
        EXPECT_TRUE(_succeed);

        EXPECT_EQ(cSourceAddress, _message.GetSourceAddress());
        EXPECT_EQ(cActivationType, _message.GetActivationType());
    }

    TEST(RoutingActivationRequestTest, DeserializationUsingOemData)
    {
        const uint32_t cExpectedResult{0x12345678};
        const std::vector<uint8_t> cSerializedMessage{
            0x02, 0xfd, 0x00, 0x05, 0x00, 0x00, 0x00, 0x0b,
            0x00, 0x01, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x12, 0x34, 0x56, 0x78};

        RoutingActivationRequest _message;
        bool _succeed{_message.TryDeserialize(cSerializedMessage)};
        EXPECT_TRUE(_succeed);

        uint32_t _actualResult;
        _succeed = {_message.TryGetOemSpecificData(_actualResult)};
        EXPECT_TRUE(_succeed);
        EXPECT_EQ(cExpectedResult, _actualResult);
    }

    TEST(RoutingActivationRequestTest, InvalidDeserialization)
    {
        const std::vector<uint8_t> cSerializedMessage{
            0x02, 0xfd, 0x00, 0x05, 0x00, 0x00, 0x00, 0x00};

        RoutingActivationRequest _message;
        bool _succeed{_message.TryDeserialize(cSerializedMessage)};
        EXPECT_FALSE(_succeed);
    }
}