//
// Created by yurunyang on 2018/8/23.
//

#ifndef THE_NEW_FAKE_SQL_FILE_READ_WRITE_SYSTEM_H
#define THE_NEW_FAKE_SQL_FILE_READ_WRITE_SYSTEM_H


#include <ios>
#include <fstream>
namespace utils
{


//    template  <class valuetype>
    class basic_read_write
    {
    private:
       std::fstream  thefile;

    public:
        basic_read_write(char *datafile);
        int insert_value(std::string value);
        void read_value();
    };
}







#endif //THE_NEW_FAKE_SQL_FILE_READ_WRITE_SYSTEM_H
