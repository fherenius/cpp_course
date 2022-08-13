#include <iostream>
#include "storage.h"

enum class TcpUdp
{
  SECONDS = 1,
  MU_SECONDS,              
  PROTOCOL,       // tcp/udp
  SRC,
  DST,
  SPORT,
  DPORT,
  SENTPACKETS,
  SENTBYTES,
  RECVDPACKETS,
  RECVDBYTES,
  nFields,
};
    
enum class Icmp
{
  SECONDS   =   1,
  MU_SECONDS,              
  SRC,
  DST,
  ID,
  SENTPACKETS,
  SENTBYTES,
  RECVDPACKETS,
  RECVDBYTES,
  nFields,
};

int main()
{
  Storage storage;

  std::cout << storage[Icmp::ID]           << '\n' <<
               storage[TcpUdp::PROTOCOL]   << '\n' <<
               storage[12]                 << '\n' <<
               storage['a']                << '\n' <<
               storage[12.5]               << '\n';
}