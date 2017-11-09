//http://www.linuxhowtos.org/C_C++/socket.htm
//http://beej.us/guide/bgnet/output/html/multipage/syscalls.html#getaddrinfo

#ifndef MSOCKET_H
#define MSOCKET_H

#include <string>

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h> 

class MSocket
{
public:
    MSocket();
    ~MSocket();
    int init();
    
    int Msend(std::string msg);
    std::string Mrecv();

private:
    int status;
    struct addrinfo hints;
    struct addrinfo *res;
    int sockfd;
    char recv_buffer[100000];
};

#endif
