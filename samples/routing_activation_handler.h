#ifndef ROUTING_ACTIVATION_HANDLER_H
#define ROUTING_ACTIVATION_HANDLER_H

#include<set>

#include "../include/doiplib/message_handler.h"
#include "../include/doiplib/routing_activation_request.h"
#include "../include/doiplib/routing_activation_response.h"

namespace DoipLib
{
    class RoutingActivationHandler : public MessageHandler
    {
    private:
        static const uint8_t cSupportedActivationType{0x00U};
        static const bool cHasOemSpecificData{false};

        const uint8_t cProtocolVersion;
        const uint16_t cLogicalAddress;

        mutable std::set<uint16_t> mActiveTesters;
        RoutingActivationRequest mRequest;

    public:
        RoutingActivationHandler(
            uint8_t protocolVersion,
            uint16_t logicalAddress);

        Message *GetMessage() override;

        bool TryHandle(
            const Message *request, std::vector<uint8_t> &response) const override;
    };
}

#endif