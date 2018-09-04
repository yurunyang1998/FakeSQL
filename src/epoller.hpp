//
// Created by falleuion on 8/19/18.
//

#ifndef EPOLLER_HPP_
#define EPOLLER_HPP_

#include <sys/epoll.h>
#include <vector>
#include <utility>
#include <set>
#include <map>

#include "netutils.hpp"

#include <boost/core/noncopyable.hpp>

namespace net {


typedef std::vector<Channel *>ChannelList;

class EPoller : public boost::noncopyable {
public:
    EPoller(EventLoop *loop);
    ~EPoller();
    void update_channels(Channel *);
    void remove_channels(Channel *);
    void poller(int timeout, ChannelList &list);
    void update(int operation, Channel *channel);

private:
    void fill_active_channels(int num, ChannelList &list) const;

    std::map<int, Channel*> channels_map_;
    int epollfd_;
    std::vector<struct epoll_event> events_;
    std::set<std::pair<int, Channel *>> channels_;
    EventLoop *ownerloop_;
};



} // end of net


#endif //EPOLLER_HPP
