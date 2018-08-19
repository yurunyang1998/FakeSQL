//
// Created by falleuion on 8/19/18.
//

#ifndef EPOLLER_HPP_
#define EPOLLER_HPP_

#include <sys/epoll.h>
#include <vector>
#include <utility>
#include <set>

#include <boost/core/noncopyable.hpp>

namespace net {

class Channel;

typedef std::vector<Channel *>ChannelList;

class EPoller : public boost::noncopyable {
public:
    EPoller();
    ~EPoller();
    void update_channels(Channel *);
    void poller(int timeout, ChannelList &list);

private:
    void fill_active_channels(int num, ChannelList &list);

    int epollfd;
    std::vector<struct epoll_event> events_;
    std::set<std::pair<int, Channel *>> channels_;
};



} // end of net


#endif //EPOLLER_HPP
