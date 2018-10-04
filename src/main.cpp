#include <iostream>
#include "module.h"
#include "socket.hpp"
#include "hyperfine_structure.hpp"

int main(int argc, const char *argv[])
{
    module *mod;
    int res;
    char demo[] = "CREATE TABLE Person\n"
                  "(\n"
                  "Id int,\n"
                  "LastName varchar(255),\n"
                  "FirstName varchar(255),\n"
                  "Address varchar(255),\n"
                  "City varchar(255)\n"
                  ");";

    mod = new_module_from_string(demo);
    res = parse_module(mod);
    delete_module(mod);

    return 0;

}
