//
// Created by falleuion on 9/3/18.
//

#include "thread_loop.hpp"
#include "netutils.hpp"
#include "epoller.hpp"

namespace net {

EventLoop::EventLoop()
    : looping_(false), quit_(false), poller(new EPoller(this)),
      active_channels()
{

}


EventLoop::~EventLoop()
{

}

void EventLoop::updatechannel(net::Channel *channel)
{
    assert(channel->owner_loop() == this);
    poller->update_channels(channel);
}

void EventLoop::removechannel(net::Channel *channel)
{
    assert(channel->owner_loop() == this);
    poller->remove_channels(channel);
}


void EventLoop::run()
{
    assert(!looping_);
}

void EventLoop::quit()
{

}

}  // end of net

