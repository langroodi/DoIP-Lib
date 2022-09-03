#include "doiplib/generic_nack.h"

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
        const std::size_t cNackCodeIndex{cHeaderSize};

        if (payload.size() > cNackCodeIndex)
        {
            uint8_t _nackCodeByte{payload.at(cNackCodeIndex)};
            mNackCode = static_cast<NackType>(_nackCodeByte);

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