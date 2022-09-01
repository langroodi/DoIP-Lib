#include <array>
#include <iterator>
#include <algorithm>
#include <gtest/gtest.h>
#include <doiplib/convert.h>

namespace DoipLib
{
    TEST(ConvertTest, ShortToByteArray)
    {
        const uint16_t cNumber{0x1234};
        const std::array<uint8_t, sizeof(uint16_t)> cExpectedResult{0x12, 0x34};

        std::vector<uint8_t> _actualResult;
        Convert::ToByteArray<uint16_t>(cNumber, _actualResult);

        bool _areEqual =
            std::equal(
                std::cbegin(cExpectedResult),
                std::cend(cExpectedResult),
                std::cbegin(_actualResult));
        EXPECT_TRUE(_areEqual);
    }

    TEST(ConvertTest, IntegerToByteArray)
    {
        const uint32_t cNumber{0x12345678};
        const std::array<uint32_t, sizeof(uint32_t)> cExpectedResult{0x12, 0x34, 0x56, 0x78};

        std::vector<uint8_t> _actualResult;
        Convert::ToByteArray<uint32_t>(cNumber, _actualResult);

        bool _areEqual =
            std::equal(
                std::cbegin(cExpectedResult),
                std::cend(cExpectedResult),
                std::cbegin(_actualResult));
        EXPECT_TRUE(_areEqual);
    }

    TEST(ConvertTest, ByteArrayToShort)
    {
        const uint16_t cExpectedResult{0x1234};
        std::vector<uint8_t> _byteArray{0x12, 0x34};
        std::size_t _offset{0};

        auto _actualResult{Convert::ToUnsignedInteger<uint16_t>(_byteArray, _offset)};

        EXPECT_EQ(cExpectedResult, _actualResult);
        EXPECT_EQ(sizeof(uint16_t), _offset);
    }

    TEST(ConvertTest, ByteArrayToInteger)
    {
        const uint32_t cExpectedResult{0x12345678};
        std::vector<uint8_t> _byteArray{0x12, 0x34, 0x56, 0x78};
        std::size_t _offset{0};

        auto _actualResult{Convert::ToUnsignedInteger<uint32_t>(_byteArray, _offset)};

        EXPECT_EQ(cExpectedResult, _actualResult);
        EXPECT_EQ(sizeof(uint32_t), _offset);
    }
}