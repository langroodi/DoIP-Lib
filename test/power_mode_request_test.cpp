#include <gtest/gtest.h>
#include <doiplib/power_mode_request.h>

namespace DoipLib
{
    TEST(PowerModeRequestTest, ValidDeserialization)
    {
        const std::vector<uint8_t> cSerializedMessage{
            0x02, 0xfd, 0x40, 0x03, 0x00, 0x00, 0x00, 0x00};

        PowerModeRequest _message;
        bool _succeed{_message.TryDeserialize(cSerializedMessage)};
        EXPECT_TRUE(_succeed);
    }
}