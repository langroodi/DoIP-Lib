#include <iterator>
#include <algorithm>
#include <gtest/gtest.h>
#include <doiplib/eid_vehicle_id_request.h>

namespace DoipLib
{
    TEST(EidVehicleIdRequestTest, Serialization)
    {
        const uint8_t cProtocolVersion{0x02};
        const std::size_t cEidSize{6};
        const std::array<uint8_t, cEidSize> cEid{
            0xaa, 0xbb, 0xcc, 0xdd, 0xee, 0xff};
        const std::size_t cPayloadLength{14};
        const std::array<uint8_t, cPayloadLength> cExpectedResult{
            0x02, 0xfd, 0x00, 0x02, 0x00, 0x00, 0x00, 0x06,
            0xaa, 0xbb, 0xcc, 0xdd, 0xee, 0xff};

        EidVehicleIdRequest _message(cProtocolVersion, cEid);
        std::vector<uint8_t> _actualResult;
        _message.Serialize(_actualResult);

        bool _areEqual =
            std::equal(
                std::cbegin(cExpectedResult),
                std::cend(cExpectedResult),
                std::cbegin(_actualResult));
        EXPECT_TRUE(_areEqual);
    }

    TEST(EidVehicleIdRequestTest, ValidDeserialization)
    {
        const std::size_t cEidSize{6};
        const std::array<uint8_t, cEidSize> cExpectedResult{
            0xaa, 0xbb, 0xcc, 0xdd, 0xee, 0xff};
        const std::vector<uint8_t> cSerializedMessage{
            0x02, 0xfd, 0x00, 0x02, 0x00, 0x00, 0x00, 0x06,
            0xaa, 0xbb, 0xcc, 0xdd, 0xee, 0xff};

        EidVehicleIdRequest _message;
        bool _succeed{_message.TryDeserialize(cSerializedMessage)};
        EXPECT_TRUE(_succeed);

        std::array<uint8_t, cEidSize> _actualResult{_message.GetEid()};
        EXPECT_EQ(cExpectedResult, _actualResult);
    }

    TEST(EidVehicleIdRequestTest, InvalidDeserialization)
    {
        const std::vector<uint8_t> cSerializedMessage{
            0x02, 0xfd, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00};

        EidVehicleIdRequest _message;
        bool _succeed{_message.TryDeserialize(cSerializedMessage)};
        EXPECT_FALSE(_succeed);
    }
}