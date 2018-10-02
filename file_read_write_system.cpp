//
// Created by yurunyang on 2018/8/23.
//

#include "file_read_write_system.h"
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <unistd.h>

using namespace std;
using  namespace utils;

basic_read_write::basic_read_write(char *namepath) {
    fd = ::open(namepath,O_RDWR,S_IREAD| S_IWUSR); //  only open the file when it has existed
    if(fd == -1)    // if the file not exist
    {
        fd = ::open(namepath,O_RDWR | O_CREAT,S_IREAD|S_IWUSR); // create the datafile
        if(fd == -1)
        {
            std::cout<<"open datafile error"<<std::endl;
            return ;
        }

        char whethe_initial ='0';
        write(fd,&whethe_initial,1);
        wtdhbw = '0';
    }
    else
    {
        ::read(fd,&wtdhbw,1);

    }


}

