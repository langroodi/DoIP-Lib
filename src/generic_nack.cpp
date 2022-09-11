#include "doiplib/generic_nack.h"
#include "doiplib/convert.h"

namespace DoipLib
{
    const PayloadType GenericNack::cPayloadType;

    GenericNack::GenericNack() noexcept : Message(cPayloadType)
    {
    }

    GenericNack::GenericNack(
        uint16_t protocolVersion,
        NackType nackCode) noexcept : Message(protocolVersion, cPayloadType),
                                      mNackCode{nackCode}
    {
    }

    void GenericNack::GetPayload(std::vector<uint8_t> &payload)
    {
        auto _nackCodeByte{static_cast<uint8_t>(mNackCode)};
        payload.insert(payload.begin(), _nackCodeByte);
    }

    bool GenericNack::TrySetPayload(const std::vector<uint8_t> &payload)
    {
        const std::size_t cExpectedSize{cHeaderSize + sizeof(NackType)};
        std::size_t _offset{cHeaderSize};

        if (payload.size() == cExpectedSize)
        {
            mNackCode = Convert::ToEnum<NackType>(payload, _offset);
            return true;
        }
        else
        {
            return false;
        }
    }

    NackType GenericNack::GetNackCode() const noexcept
    {
        return mNackCode;
    }
}