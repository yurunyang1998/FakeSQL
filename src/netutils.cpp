//
// Created by falleuion on 8/18/18.
//

#include "netutils.hpp"
#include <cstring>
#include <arpa/inet.h>

namespace net {

    Inetaddr::Inetaddr(int port)
    {
        memset(&connaddr_, 0, sizeof(struct sockaddr));
        connaddr_.sin_addr.s_addr = INADDR_ANY;
        connaddr_.sin_family = AF_INET;
        connaddr_.sin_port = htons(port);
    }

    Inetaddr::Inetaddr(int port, const std::string ip)
    {
        memset(&connaddr_, 0, sizeof(struct sockaddr));
        if(inet_pton(AF_INET, ip.c_str(), &connaddr_.sin_addr) < 0) {
            perror("convert IP address failed");
            exit(-1);
        }
        connaddr_.sin_family = AF_INET;
        connaddr_.sin_port = htons(port);
    }


    Inetaddr::~Inetaddr()
    { }

}
