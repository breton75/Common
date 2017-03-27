#ifndef SYSCONFIGSTRUCT
#define SYSCONFIGSTRUCT

#include <QObject>
#include <QDebug>

#pragma pack(push, 1)
struct STRUCT_SYS_CONFIG
{
  uchar ip[4];
  uint port;
  uchar mac[6];
};
#pragma pack(pop)

namespace {
bool fillStruct(STRUCT_SYS_CONFIG* str,
                void *ip, size_t sizeof_ip,
                void *port, size_t sizeof_port,
                void *mac, size_t sizeof_mac);

}

/***************************************************************************/

bool fillStruct(STRUCT_SYS_CONFIG* str,
                void* ip, size_t sizeof_ip,
                void* port, size_t sizeof_port,
                void* mac, size_t sizeof_mac)
{
  memcpy((void*)str, ip, sizeof_ip);
  memcpy((void*)str + sizeof_ip, port, sizeof_port);
  memcpy((void*)str + sizeof_ip + sizeof_port, mac, sizeof_mac);
}

#endif // SYSCONFIGSTRUCT

