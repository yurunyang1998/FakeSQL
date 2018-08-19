//
// Created by falleuion on 8/19/18.
//

#include "epoller.hpp"
#include <cstdio>

namespace net {

EPoller::EPoller()
    : epollfd(::epoll_create1(EPOLL_CLOEXEC)), events_(15)
{
    if(epollfd < 0) {
        perror("epoll_create1");
        exit(-1);
    }
}

EPoller::~EPoller()
{
    ::close(epollfd);
}


// TODO
void EPoller::fill_active_channels(int num, ChannelList &list)
{

}

void EPoller::update_channels(Channel* channel)
{

}

void EPoller::poller(int timeout, net::ChannelList &list)
{

}

} // end of net

