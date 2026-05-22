#include "network/NetworkInterface.hpp"

network::NetworkInterface::NetworkInterface(struct ifaddrs *ifa)
{
  m_ifa = ifa;

  getifaddrs(&m_ifa);

  for (struct ifaddrs *ifa = m_ifa; ifa != nullptr; ifa = ifa->ifa_next) {

    if (ifa->ifa_addr && ifa->ifa_addr->sa_family == AF_INET) {
      m_sockaddr = (struct sockaddr_in *)ifa->ifa_addr;
      m_addresses[ifa->ifa_name] = *m_sockaddr;

      if (ifa->ifa_name == LOCALHOST_INTERFACE)
        continue;

      int pid = fork()
    }
  }



}

network::NetworkInterface::~NetworkInterface()
{
  freeifaddrs(m_ifa);
}

std::string network::NetworkInterface::getName() const
{
  return std::string();
}

std::map<std::string, sockaddr_in> network::NetworkInterface::getAddress() const
{
  return m_addresses;
}

std::ostream &network::operator<<(std::ostream &os, const network::NetworkInterface &ni)
{
  os << "Network Interface: " << ni.getName() << std::endl;
  for (const auto &address : ni.getAddress()) {
    os << "  Address: " << inet_ntoa(address.second.sin_addr) << std::endl;
  }
  return os;
}
