//
// Created by falleuion on 8/18/18.
//

#ifndef SOCKET_HPP_
#define SOCKET_HPP_

#include <boost/noncopyable.hpp>
#include <cerrno>
#include "netutils.hpp"

namespace net {

    /// The `Socket' class will maintain a connection during its lifetime..
class Socket: public boost::noncopyable {
public:
    // create a socket file descriptor
    explicit Socket();
    ~Socket();

    int fd() const { return fd_; }
    void bind(Inetaddr &);
    void listen();
    int set_port_reuse();
    int set_addr_reuse();
    int set_sock_nodelay();

private:
    const int fd_;

};


}



#endif //SOCKET_HPP_
