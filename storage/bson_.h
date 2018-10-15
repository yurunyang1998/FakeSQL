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
        uint8_t *buf;
        size_t buflen;


    public:
        bson_couple();
        ~bson_couple();
        bson_t * get_bson();
        void  insert_UTF8_value(std::string attribute,std::string value);
        void  insert_int32_value(std::string attribute,int32_t value);
        size_t  getBsonLength();
        uint8_t*  getBsonBuf();
        bson_t* rebuildFromBuffer(const uint8_t * buf);


    };



}





#endif //THE_NEW_FAKE_SQL_BSON_H

