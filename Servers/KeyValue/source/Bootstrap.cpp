#include "Bootstrap.h"

namespace IB::Server {
    void Run(const IBConfig& config) {
        Logger::Init(config.name, config.logLevel);

        IB_LOG_INFO("InfraBase {} Initialized", config.name);

        Socket socket(config.port);

        while (true) {

        }
    }
}