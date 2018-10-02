//
// Created by yurunyang on 2018/8/23.
//

#ifndef THE_NEW_FAKE_SQL_FILE_READ_WRITE_SYSTEM_H
#define THE_NEW_FAKE_SQL_FILE_READ_WRITE_SYSTEM_H


#include <ios>
#include <fstream>
#include <sys/stat.h>
#include <fcntl.h>
#include <iostream>
namespace utils
{


//    template  <class valuetype>
    class basic_read_write
    {
    private:

        int fd;
        char wtdhbw; //whether the datafile has been writen


    public:
        basic_read_write(char * namepath);

    };
}







#endif //THE_NEW_FAKE_SQL_FILE_READ_WRITE_SYSTEM_H
