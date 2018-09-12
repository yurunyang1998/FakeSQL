//
// Created by yurunyang on 2018/8/23.
//

#include "file_read_write_system.h"
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <cstring>

using namespace std;
using  namespace utils;

basic_read_write::basic_read_write(char *datafile) {
    thefile.open(datafile,ios::in | ios::out | ios::binary | ios::trunc);
    if(thefile.is_open())
    {
        cout<<"open successed"<<endl;
    }

}

struct test
{
    int v=1324;
};

int basic_read_write::insert_value(string value) {
    if(thefile.is_open())
    {
//        const  char *value_char = ;
//        thefile.write(value_char,value.length());
//        cout<<"write succeed "<<endl;


        struct test atest;

        char d[sizeof(struct test)];
        memcpy(d,&atest, sizeof(atest));
        thefile<<d;

        return 1;
    }
    else
    {
        cout<<"the datafile has not be opened"<<endl;
        return -1;
    }
}


void basic_read_write::read_value() {

    if(thefile.is_open())
    {
        cout<<"load successed";
        char a[sizeof(struct test)];
        struct test atest;
        thefile>>atest.v;
        //cout<<a;
        //memcpy(&atest,a,sizeof(struct test));
        cout<<atest.v;

    }
}


//std::ofstream  file;
//file.open("../test", std::ios::binary);
//if(file.is_open())
//{
//
////int size = file.tellg();
//char name[] = "yurunyangyangyangyang";
//file.write(name, sizeof(name));
//file.close();
//
////std::cout<<"hehe";
//}
//std::ifstream files("../test",std::ios::binary);
//if(files.is_open())
//{
//std::cout<<"aa";
//char names[20];
//files.read(names,20);
//std::cout<<names;
//}
