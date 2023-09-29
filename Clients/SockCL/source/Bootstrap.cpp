#include "Bootstrap.h"

namespace IB::Client {
    void Run(const IBConfig& config) {
        Logger::Init(config.name, config.logLevel);

        IB_LOG_INFO("InfraBase {} Initialized", config.name);

        while (true) {

        }
    }
}