#ifndef DOIP_CONTROLLER_H
#define DOIP_CONTROLLER_H

#include "./controller_config.h"

namespace DoipLib
{
    /// @brief DoIP controller to route and handle DoIP messages
    class DoipController
    {
    private:
        ControllerConfig mConfiguration;
        
    public:
        /// @brief Constructor
        /// @param configuration Controller configurtation
        DoipController(ControllerConfig&& configuration) noexcept;
    };
}

#endif