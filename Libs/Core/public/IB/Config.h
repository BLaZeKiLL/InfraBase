#pragma once

#include "Logger.h"

namespace IB {
    struct IBConfig {
        const std::string& name;
        const std::string& port;
        const Logger::ib_log_level logLevel;
    };
}
