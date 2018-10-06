//
// Created by falleuion on 9/16/18.
//

#ifndef THE_NEW_FAKE_SQL_BSON_H
#define THE_NEW_FAKE_SQL_BSON_H


#include <array>

#include <bson.h>
#include <map>

namespace bson_
{
    class bson_couple
    {
    private:
        bson_t *b;
        bson_writer_t *writer;
        uint8_t *buf = NULL;
        size_t buflen = 0;


    public:
        bson_couple();
        ~bson_couple();

        void  insert_UTF8_value(std::string attribute,std::string value);
        void  insert_int32_value(std::string attribute,int32_t value);
        size_t  getBsonLength();
        uint8_t*  getBsonBuf();



    };



}





#endif //THE_NEW_FAKE_SQL_BSON_H

