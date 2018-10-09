//
// Created by falleuion on 9/3/18.
//

#ifndef THREAD_LOOP_H_
#define THREAD_LOOP_H_

#include <vector>

#include <boost/scoped_ptr.hpp>
#include <boost/core/noncopyable.hpp>

namespace net
{

class EPoller;

class Channel;

typedef std::vector<Channel *> ChannelList;


class EventLoop : public boost::noncopyable
{
public:
    EventLoop();
    ~EventLoop();
    void run();
    void quit();
    void updatechannel(Channel *channel);
    void removechannel(Channel *channel);
private:
    bool quit_;
    bool looping_;
    boost::scoped_ptr<EPoller> poller;
    ChannelList active_channels;
};

}  // end of net

#endif //THREAD_LOOP_H_
