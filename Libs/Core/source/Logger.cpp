//
// Created by Devashish Lal on 7/15/23.
//

#include <spdlog/sinks/stdout_color_sinks.h>

#include "IB/Logger.h"

namespace IB {
    Logger::ib_logger Logger::m_MainLogger; // static definition

    void Logger::Init(const std::string& name, const ib_log_level& level) {
        spdlog::set_pattern("%^[%n][%T][%4!l]%$ : %v");

        m_MainLogger = spdlog::stdout_color_mt(name);
        m_MainLogger->set_level(level);
    }
}

