//
// Created by yurunyang on 18-9-20.
//

#include <iostream>
#include "bson_.h"
using  namespace bson_;
bson_couple::bson_couple() {
    b = bson_new();
    writer = bson_writer_new (&buf, &buflen, 0, bson_realloc_ctx, NULL);

}

bson_couple::~bson_couple() {
    bson_destroy(b);
}

void bson_couple::insert_UTF8_value
        (std::string attribute, std::string value) {

    bson_error_t error;

    try {
        bson_writer_begin (writer, &b);
        bool result = bson_append_utf8(b,attribute.c_str(),-1,value.c_str(),-1);
        bson_writer_end(writer);
        if(result== false)
        {
            throw false;

        }
    }
    catch(bool a)
    {
        bson_writer_rollback(writer);
        std::cout<<error.code<<std::endl;

    }

}


void bson_couple::insert_int32_value(std::string attribute, int32_t value) {


    bson_error_t error;

    try {

        bson_writer_begin(writer,&b);

        bool result = bson_append_int32(b,attribute.c_str(),-1,value);

        bson_writer_end(writer);
        if(result== false)
            throw false;
    }
    catch(bool a)
    {
        bson_writer_rollback(writer);
        std::cout<<"error";
        std::cout<<error.code<<std::endl;
    }
}

uint8_t* bson_couple::getBsonBuf() {
    return this->buf;
}

size_t bson_couple::getBsonLength() {
    return bson_writer_get_length(writer);
}