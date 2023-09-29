#pragma once

#include <string>

namespace IB {
    class Socket {
    private:
        int m_fd;
    public:
        explicit Socket(const std::string& port);
        ~Socket();

        /**
         * Server call
         */
        void Listen() const;

        /**
         * Client call
         */
        void Connect() const;

        inline int GetFD() const { return m_fd; }
    private:
    };
}