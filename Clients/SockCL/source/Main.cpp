#include "Bootstrap.h"

int main() {
    IB::IBConfig config = {
        "SockCL",
        "2500", // this is the server's port
        spdlog::level::info
    };

    IB::Client::Run(config);
}