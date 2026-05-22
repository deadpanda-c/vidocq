#include <iostream>
#include <ifaddrs.h>

#include "network/NetworkInterface.hpp"

int main(void)
{
  struct ifaddrs *addrs = nullptr;

  network::NetworkInterface interface = network::NetworkInterface(addrs);

  std::cout << "INTERFACES:" << interface << std::endl;
  return 0;
}
