//
// Created by falleuion on 8/18/18.
//

#include "socket.hpp"
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <cstdio>
#include <fcntl.h>
#include <netinet/tcp.h>

namespace net {

Socket::Socket()
    : fd_(::socket(AF_INET, SOCK_STREAM, 0))
{
    if(fd_ < 0) {
        perror("Oops! create socket failed!");
        exit(-1);
    }
}

Socket::~Socket()
{
    ::close(fd_);
}

void Socket::bind(const Inetaddr &addr)
{
    if(::bind(fd_, addr.to_addr(), addr.to_length()) < 0) {
        perror("bind socket address failed");
        exit(-1);
    }
}

void Socket::listen()
{
    if(::listen(fd_, SOMAXCONN) < 0) {
        perror("listen socket failed?");
        exit(-1);
    }
}

int Socket::set_addr_reuse()
{
    int val = 1, ret;
    if((ret = ::setsockopt(fd_, SOL_SOCKET, SO_REUSEADDR, &val, sizeof(val))) < 0) {
        perror("setsockopt SQ_REUSEADDR");
    }
    return ret;
}

int Socket::set_port_reuse()
{
    int val = 1, ret;
    if((ret = ::setsockopt(fd_, SOL_SOCKET, SO_REUSEPORT, &val, sizeof(val))) < 0) {
        perror("setsockopt SO_REUSEPORT");
    }
    return ret;
}

int Socket::set_sock_nodelay()
{
    int val = 1, ret;
    if((ret = ::setsockopt(fd_, IPPROTO_TCP, TCP_NODELAY, &val, sizeof(val))) < 0) {
        perror("setsockopt TCP_NODELAY");
    }
    return ret;
}

//
//Connector::Connector(const Inetaddr &addr)
//    : channelobj_(sockobj_.fd())
//{
//    sockobj_.set_addr_reuse();
//    sockobj_.bind(addr);
//}
//
//Connector::~Connector()
//{
//    channelobj_.disable_all();
//}
//
//void Connector::make_listen()
//{
//    sockobj_.listen();
//    channelobj_.enable_read();
//}

} // end of net
