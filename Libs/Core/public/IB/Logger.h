//
// Created by Devashish Lal on 7/15/23.
//

#pragma once

#include <memory>
#include <spdlog/spdlog.h>

namespace IB {
    class Logger {
    public: // Public Aliases for simpler types
        using ib_logger = std::shared_ptr<spdlog::logger>;
        using ib_log_level = spdlog::level::level_enum;

    private:
        static ib_logger m_MainLogger; // static declaration

    public:
        static void Init(const std::string& name, const ib_log_level& level);

        inline static ib_logger& GetMainLogger() {
            return m_MainLogger;
        }
    };
}

#define IB_LOG_ERROR(...) IB::Logger::GetMainLogger()->error(__VA_ARGS__)
#define IB_LOG_WARN(...) IB::Logger::GetMainLogger()->warn(__VA_ARGS__)
#define IB_LOG_INFO(...) IB::Logger::GetMainLogger()->info(__VA_ARGS__)
#define IB_LOG_DEBUG(...) IB::Logger::GetMainLogger()->debug(__VA_ARGS__)
#define IB_LOG_TRACE(...) IB::Logger::GetMainLogger()->trace(__VA_ARGS__)



