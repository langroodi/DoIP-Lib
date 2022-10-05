#ifndef CONTROLLER_CONFIG_H
#define CONTROLLER_CONFIG_H

#include <stdint.h>

namespace DoipLib
{
    /// @brief DoIP controller configuration data structure
    /// @see DoipController
    struct ControllerConfig
    {
        /// @brief Maximum DoIP request payload length
        uint32_t doipMaxRequestBytes;
    };
}

#endif