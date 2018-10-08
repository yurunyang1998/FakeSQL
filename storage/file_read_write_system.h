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
#include "bson_.h"
#include "bson.h"
namespace utils
{


//    template  <class valuetype>
    class basic_read_write
    {
    private:

        int fd;
        //char wtdhbw; //whether the datafile has been writen
        off64_t nowSeek=0; //where the seek is  And  before the seek ,the file has been writen

    public:
        basic_read_write(char * namepath);
        ~basic_read_write();
        off64_t write_bsonCouple(bson_::bson_couple *bsonCouple_,uint8_t *bsonBuf);

    };
}







#endif //THE_NEW_FAKE_SQL_FILE_READ_WRITE_SYSTEM_H
