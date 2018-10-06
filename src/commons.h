//
// Created by falleuion on 10/4/18.
//

#ifndef COMMONS_H
#define COMMONS_H

#include <stdint.h>

enum OprtType
{
    TS_CREATE, TS_INSERT, TS_SELECT, TS_DELETE
};


static uint8_t __Sql_NOTNULLX = 0x01;
static uint8_t __Sql_AUTOINC = 0x02;
static uint8_t __Sql_UNIKEY = 0x04;
static uint8_t __Sql_PRIKEY = 0x08;
static uint8_t __Sql_KEY = 0x10;

static uint8_t __SqlInsOpt_LOWPRI = 0x01;           // Low Priority
static uint8_t __SqlInsOpt_DELAYED = 0x02;
static uint8_t __SqlInsOpt_HIGPRI = 0x04;           // High Priority
static uint8_t __SqlInsOpt_IGNORE = 0x08;

static uint8_t __Sql_INTNUM = 0x01;
static uint8_t __Sql_NAME = 0x02;
static uint8_t __Sql_USERVAR = 0x04;
static uint8_t __Sql_STRING = 0x08;
static uint8_t __Sql_BOOL = 0x10;




#endif //COMMONS_H
