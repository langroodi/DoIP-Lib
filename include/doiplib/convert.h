#ifndef CONVERT_H
#define CONVERT_H

#include <stdint.h>
#include <vector>

namespace DoipLib
{
    /// @brief Helper functions namespace for unsinged integers to byte arrays conversion and vice versa
    namespace Convert
    {
        static const std::size_t cByteOffset{8};
        static const uint8_t cByteMask{0xff};

        /// @brief Convert the given unsigned integer to a byte array
        /// @tparam T Unsigned integer type
        /// @param[in] unsignedInteger Unsigned integer to be converted
        /// @param[out] byteArray Byte array as the unsigned integer conversion result
        template <typename T>
        void ToByteArray(T unsignedInteger, std::vector<uint8_t> &byteArray)
        {
            const std::size_t cUnsignedIntegerSize{sizeof(T)};

            for (std::size_t i = 0; i < cUnsignedIntegerSize; ++i)
            {
                auto _byte{static_cast<uint8_t>(unsignedInteger & cByteMask)};
                byteArray.insert(byteArray.begin(), _byte);
                unsignedInteger >>= cByteOffset;
            }
        }

        /// @brief Convert the given byte array to an unsigned integer
        /// @tparam T Unsigned integer type
        /// @param byteArray Byte array to be converted
        /// @param[inout] offset Offset within byte array
        /// @return Unsigned integer as the byte array conversion result
        template <typename T>
        T ToUnsignedInteger(const std::vector<uint8_t> &byteArray, std::size_t &offset = 0)
        {
            const std::size_t cUnsignedIntegerSize{sizeof(T)};

            auto _offsetUpperBound{static_cast<std::size_t>(offset + cUnsignedIntegerSize)};

            T _result{byteArray.at(offset)};

            for (++offset; offset < _offsetUpperBound; ++offset)
            {
                _result <<= cByteOffset;
                _result += byteArray.at(offset);
            }

            return _result;
        }
    }
}

#endif