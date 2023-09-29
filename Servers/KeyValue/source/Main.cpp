//
// Created by Devashish Lal on 7/15/23.
//

#include "Bootstrap.h"

int main() {
    IB::IBConfig config { // Initializer list so const char* -> std::string conversions are taken care of
        "KeyValue",
        "2500",
        spdlog::level::info
    };

    IB::Server::Run(config);
}