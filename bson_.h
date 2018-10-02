//
// Created by falleuion on 9/16/18.
//

#ifndef THE_NEW_FAKE_SQL_BSON_H
#define THE_NEW_FAKE_SQL_BSON_H


#include <array>

#include <bson.h>
namespace bson_
{
    class create_bson_couple
    {
    private:
        bson_t *b;

    public:
        create_bson_couple();
        ~create_bson_couple();

        void  insert_UTF8_value(std::string attribute,std::string value);
        void  insert_int32_value(std::string attribute,int32_t value);



    };



}





#endif //THE_NEW_FAKE_SQL_BSON_H

