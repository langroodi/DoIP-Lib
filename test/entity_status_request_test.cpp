#include <gtest/gtest.h>
#include <doiplib/entity_status_request.h>

namespace DoipLib
{
    TEST(EntityStatusRequestTest, ValidDeserialization)
    {
        const std::vector<uint8_t> cSerializedMessage{
            0x02, 0xfd, 0x40, 0x01, 0x00, 0x00, 0x00, 0x00};

        EntityStatusRequest _message;
        GenericNackType _nackCode;
        bool _succeed{_message.TryDeserialize(cSerializedMessage, _nackCode)};
        EXPECT_TRUE(_succeed);
    }
}