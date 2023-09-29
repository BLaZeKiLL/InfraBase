#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#include "IB/Logger.h"
#include "IB/Socket.h"

namespace IB {
    Socket::Socket(const std::string &port) {
        addrinfo hints, *res, *p;

        char ipstr[INET_ADDRSTRLEN];

        int rc = 0;

        // Resets memory to 0 to make sure all hints are at their default values
        memset(&hints, 0, sizeof(hints));

        hints.ai_family = AF_INET; // IPv4
        hints.ai_socktype = SOCK_STREAM; // TCP

        rc = getaddrinfo("localhost", port.c_str(), &hints, &res);

        if (rc != 0) {
            IB_LOG_ERROR("Address info failed");
            freeaddrinfo(res);
            exit(1);
        }

        // res points to a linked list, so we iterate over it
        for (p = res; p != nullptr; p = p->ai_next) {
            auto addr = reinterpret_cast<sockaddr_in*>(p->ai_addr)->sin_addr;
            inet_ntop(p->ai_family, &addr, ipstr, sizeof(ipstr));
            IB_LOG_INFO("Socket ip address : {}", ipstr);
        }

        m_fd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);

        // Enable bind to same address for multiple runs
        int yes = 1;
        rc = setsockopt(m_fd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(yes));

        if (rc != 0) {
            IB_LOG_ERROR("Unable to set socket options");
            freeaddrinfo(res);
            exit(1);
        }

        // Bind is for server only
        rc = bind(m_fd, res->ai_addr, res->ai_addrlen);

        if (rc != 0) {
            IB_LOG_ERROR("Port bind failed");
            freeaddrinfo(res);
            exit(1);
        }

        IB_LOG_INFO("Socket bound to port : {}", port);

        freeaddrinfo(res); // free the linked list after lookup done
    }

    Socket::~Socket() {
        int rc = close(m_fd);

        if (rc != 0) {
            IB_LOG_ERROR("Unable to close socket");
            exit(1);
        }

        IB_LOG_INFO("Socket closed");
    }

    void Socket::Listen() const {
        // backlog is the maximum pending connections in queue after that it will reject connections
        int rc = listen(m_fd, 16);

        if (rc != 0) {
            IB_LOG_ERROR("Unable to listen on socket");
            exit(1);
        }
    }

    void Socket::Connect() const {
        //int rc = connect()
    }
}