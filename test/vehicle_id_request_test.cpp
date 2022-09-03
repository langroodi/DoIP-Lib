#include <array>
#include <iterator>
#include <algorithm>
#include <gtest/gtest.h>
#include <doiplib/vehicle_id_request.h>

namespace DoipLib
{
    TEST(VehicleIdRequestTest, ValidDeserialization)
    {
        const std::vector<uint8_t> cSerializedMessage{
            0x02, 0xfd, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00};

        VehicleIdRequest _message;
        bool _succeed{_message.TryDeserialize(cSerializedMessage)};
        EXPECT_TRUE(_succeed);
    }
}