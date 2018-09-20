//
// Created by yurunyang on 18-9-20.
//

#include <iostream>
#include "bson_.h"

create_bson_couple::create_bson_couple() {
    b = bson_new();
}

create_bson_couple::~create_bson_couple() {
    bson_destroy(b);
}

void create_bson_couple::insert_UTF8_value
        (std::string attribute, std::string value) {

    bson_error_t error;

    try {

        bool result = bson_append_utf8(b,attribute.c_str(),-1,value.c_str(),-1);
        if(result== false)
            throw false;
    }
    catch(bool a)
    {
        std::cout<<error.code<<std::endl;

    }

}


void create_bson_couple::insert_int32_value(std::string attribute, int32_t value) {


    bson_error_t error;

    try {

        bool result = bson_append_int32(b,attribute.c_str(),-1,value);
        if(result== false)
            throw false;
    }
    catch(bool a)
    {
        std::cout<<"error";
        std::cout<<error.code<<std::endl;
    }
}
