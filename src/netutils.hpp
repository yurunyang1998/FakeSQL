//
// Created by falleuion on 8/18/18.
//

#ifndef NETUTILS_HPP_
#define NETUTILS_HPP_

#include <netinet/in.h>
#include <string>
#include <boost/implicit_cast.hpp>


namespace net {

    class Inetaddr {
    public:
        explicit Inetaddr(const struct sockaddr_in &addr) : connaddr_(addr) { }
        Inetaddr(int port, const std::string ip);
        explicit Inetaddr(int port);
        ~Inetaddr();
        struct sockaddr *to_addr() { return static_cast<struct sockaddr *>(boost::implicit_cast<void *>(&connaddr_)); }
        socklen_t to_length() { return sizeof(connaddr_); }

    private:
        struct sockaddr_in connaddr_;
    };


}


#endif //FAKESQL_NETUTILS_HPP
