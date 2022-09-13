#include <gtest/gtest.h>
#include <doiplib/entity_status_request.h>

namespace DoipLib
{
    TEST(EntityStatusRequestTest, ValidDeserialization)
    {
        const std::vector<uint8_t> cSerializedMessage{
            0x02, 0xfd, 0x40, 0x01, 0x00, 0x00, 0x00, 0x00};

        EntityStatusRequest _message;
        bool _succeed{_message.TryDeserialize(cSerializedMessage)};
        EXPECT_TRUE(_succeed);
    }
}