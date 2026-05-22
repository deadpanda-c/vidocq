#pragma once

#include <ifaddrs.h>
#include <string>
#include <exception>
#include <iostream>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <map>

#define IFA_NULL "ERROR: ifa cannot be null"
#define LOCALHSOT_INTERFACE "lo"

namespace network
{
    class NetworkInterface
    {
    public:
        class NetworkInterfaceException : public std::exception
        {      
        public:
            NetworkInterfaceException(const std::string& message) : m_message(message) {}
            const char* what() const noexcept override { return m_message.c_str(); }
        private:
            std::string m_message;
        };
        NetworkInterface(struct ifaddrs* ifa);
        ~NetworkInterface();

        std::string getName() const;
        std::map<std::string, sockaddr_in> getAddress() const;

        friend std::ostream& operator<<(std::ostream& os, const NetworkInterface &networkInterface);

    private:
        struct ifaddrs *m_ifa;
        struct sockaddr_in* m_sockaddr;
        std::map<std::string, sockaddr_in> m_addresses;



    };

    std::ostream& operator<<(std::ostream& os, const NetworkInterface &networkInterface);
}
