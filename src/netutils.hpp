//
// Created by falleuion on 8/18/18.
//

#ifndef NETUTILS_HPP_
#define NETUTILS_HPP_

#include <netinet/in.h>
#include <string>
#include <boost/implicit_cast.hpp>
#include <boost/core/noncopyable.hpp>

namespace net {

class Inetaddr {
public:
    explicit Inetaddr(const struct sockaddr_in &addr) : connaddr_(addr) { }
    Inetaddr(int port, const std::string ip);
    explicit Inetaddr(int port);

    ~Inetaddr();

    const struct sockaddr * to_addr() const
    {
        return static_cast<const struct sockaddr *>(boost::implicit_cast<const void *>(&connaddr_));
    }

    socklen_t to_length() const
    {
        return sizeof(connaddr_);
    }

private:
    struct sockaddr_in connaddr_;
};


// TODO: accomplish the class of `Channel'
class Channel : public boost::noncopyable {
public:
    Channel(int fd);
    ~Channel();
    int index() const { return index_; }
    int fd() const { return fd_; }
    void set_index(int index) { index_ = index; }
    void enable_read() { event_ |= event_read_; update(); }
    void enable_write() { event_ |= event_write_; update(); }
    void disable_read() { event_ &= ~event_read_; update(); }
    void disable_write() { event_ &= ~event_write_; update(); }
    void disable_all() { event_ &= ~event_none_; update(); }


private:
    void update();
    const int fd_;
    int event_;
    int revents_;
    int index_;

    static const int event_read_;
    static const int event_write_;
    static const int event_none_;

    bool handling_event_;

};

} //end of net


#endif //FAKESQL_NETUTILS_HPP
