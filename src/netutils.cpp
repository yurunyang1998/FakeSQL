//
// Created by falleuion on 8/18/18.
//

#include "netutils.hpp"
#include <cstring>
#include <arpa/inet.h>
#include <sys/epoll.h>
#include <cassert>

namespace net {

Inetaddr::Inetaddr(int port)
{
    memset(&connaddr_, 0, sizeof(struct sockaddr));
    connaddr_.sin_addr.s_addr = INADDR_ANY;
    connaddr_.sin_family = AF_INET;
    connaddr_.sin_port = htons(port);
}

Inetaddr::Inetaddr(int port, const std::string ip)
{
    memset(&connaddr_, 0, sizeof(struct sockaddr));
    if(inet_pton(AF_INET, ip.c_str(), &connaddr_.sin_addr) < 0) {
        perror("convert IP address failed");
        exit(-1);
    }
    connaddr_.sin_family = AF_INET;
    connaddr_.sin_port = htons(port);
}


Inetaddr::~Inetaddr()
{ }


const int Channel::event_read_ = EPOLLIN | EPOLLPRI;
const int Channel::event_write_ = EPOLLOUT;
const int Channel::event_none_ = 0;


Channel::Channel(int fd)
    : fd_(fd), event_(0), revents_(0), index_(-1), handling_event_(false)
{

}

Channel::~Channel()
{
    assert(!handling_event_);
}

void Channel::update()
{
    // TODO: 将可用`Channel' 更新到调用循环中
    return ;
}


}
