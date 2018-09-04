//
// Created by falleuion on 8/18/18.
//

#ifndef SOCKET_HPP_
#define SOCKET_HPP_

#include <boost/noncopyable.hpp>
#include <cerrno>
#include <vector>
#include "netutils.hpp"

namespace net {

    /// The `Socket' class will maintain a connection during its lifetime..
class Socket: public boost::noncopyable {
public:
    // create a socket file descriptor
    explicit Socket();
    ~Socket();

    int fd() const { return fd_; }
    void bind(const Inetaddr &);
    void listen();
    int set_port_reuse();
    int set_addr_reuse();
    int set_sock_nodelay();

private:
    const int fd_;

};



class Connector : public boost::noncopyable {
public:
    Connector(const Inetaddr &addr);
    ~Connector();
    void make_listen();
    void loop();
private:
    Socket sockobj_;
    typedef std::vector<Channel *> ChannelList;

};

} // end of net



#endif //SOCKET_HPP_
