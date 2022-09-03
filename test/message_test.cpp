#include <array>
#include <iterator>
#include <algorithm>
#include <gtest/gtest.h>
#include <doiplib/message.h>

namespace DoipLib
{
    TEST(MessageTest, ValidPayloadTypeExtraction)
    {
        const PayloadType cExpectedResult{PayloadType::VehicleIdRequest};
        const std::vector<uint8_t> cSerializedMessage{
            0x02, 0xfd, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00};

        PayloadType _actualResult;
        bool _succeed{
            Message::TryExtractPayloadType(cSerializedMessage, _actualResult)};

        EXPECT_TRUE(_succeed);
        EXPECT_EQ(cExpectedResult, _actualResult);
    }

    TEST(MessageTest, InvalidPayloadTypeExtraction)
    {
        const PayloadType cExpectedResult{PayloadType::VehicleIdRequest};
        const std::vector<uint8_t> cSerializedMessage{
            0x02, 0xfd, 0x00, 0x01};

        PayloadType _actualResult;
        bool _succeed{
            Message::TryExtractPayloadType(cSerializedMessage, _actualResult)};

        EXPECT_FALSE(_succeed);
    }
}