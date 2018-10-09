//
// Created by falleuion on 8/19/18.
//

#include "epoller.hpp"
#include <cstdio>
#include <cassert>
#include <boost/implicit_cast.hpp>
#include <cstring>

namespace net {

namespace {

const int _New = -1;
const int _Added = 0;
const int _Delete = 1;

}  // end of anonymous namespace

EPoller::EPoller(EventLoop *loop)
    : epollfd_(::epoll_create1(EPOLL_CLOEXEC)), events_(15), ownerloop_(loop)
{
    if(epollfd_ < 0) {
        perror("epoll_create1");
        exit(-1);
    }
}

EPoller::~EPoller()
{
    ::close(epollfd_);
}


void EPoller::fill_active_channels(int num, ChannelList &list) const
{
    assert(static_cast<size_t>(num) <= list.size());
    for(int i = 0; i < num; i++) {
        auto channel = static_cast<Channel *>(events_[i].data.ptr);
        int fd = channel->fd();

        auto it = channels_map_.find(fd);
        assert(it != channels_map_.end());
        assert(it->second == channel);

        channel->set_revents(events_[i].events);
        list.push_back(channel);
    }

}

void EPoller::update_channels(Channel* channel)
{
    const int index = channel->index();
    if(index == _New || index == _Delete) {
        int fd = channel->fd();
        if(index == _New) {
            assert(channels_map_.find(fd) == channels_map_.end());
            channels_map_[fd] = channel;
        } else {
            assert(channels_map_.find(fd) != channels_map_.end());
            assert(channels_map_[fd] == channel);
        }

        channel->set_index(_Added);
        update(EPOLL_CTL_ADD, channel);
    } else {
        int fd = channel->fd();
        assert(channels_map_.find(fd) != channels_map_.end());
        assert(channels_map_[fd] == channel);
        assert(index == _Added);

        if(channel->is_noevent()) {
            update(EPOLL_CTL_DEL, channel);
            channel->set_index(_Delete);
        } else {
            update(EPOLL_CTL_MOD, channel);
        }
    }

}

void EPoller::poller(int timeout, net::ChannelList &list)
{
    int num_event = ::epoll_wait(epollfd_, &*events_.begin(), static_cast<int>(events_.size()), timeout);
    if(num_event >= 0) {
        fill_active_channels(num_event, list);
        if(boost::implicit_cast<size_t>(num_event) == events_.size()) {
            events_.resize(events_.size() * 2);
        }
    }

}


void EPoller::update(int operation, net::Channel *channel)
{
    struct epoll_event event;
    memset(&event, 0, sizeof(event));
    event.events = static_cast<uint32_t>(channel->get_events());
    event.data.ptr = channel;
    int fd = channel->fd();

    if(::epoll_ctl(epollfd_, operation, fd, &event) < 0) {
        if(operation == EPOLL_CTL_DEL) {
            fprintf(stderr, "epoll ctl op DEL for %d\n", fd);
        } else if(operation == EPOLL_CTL_ADD){
            fprintf(stderr, "epoll ctl op ADD for %d\n", fd);
        } else {
            fprintf(stderr, "epoll ctl op MOD for %d\n", fd);
        }
    }
}


void EPoller::remove_channels(net::Channel *)
{
    // TODO: remove channels form epoll's array.
}

} // end of net

