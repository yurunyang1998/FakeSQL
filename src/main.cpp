#include <iostream>
#include "module.h"
#include "socket.hpp"

int main(int argc, const char *argv[])
{
    module *mod;
    int res;
    char demo[] = "CREATE TABLE Person.test\n"
                  "(\n"
                  "Id int,\n"
                  "LastName varchar(255),\n"
                  "FirstName varchar(255),\n"
                  "Address varchar(255),\n"
                  "City varchar(255)\n"
                  ");\n\n"
                  "INSERT INTO Persons (LastName, Address) VALUES ('Wilson', 'Champs-Elysees');";

    mod = new_module_from_string(demo);
    res = parse_module(mod);
    delete_module(mod);

    if(res == 0) {
        std::cout << "\nSuccess!" << std::endl;
    } else {
        std::cout << "\nFailure.." << std::endl;
    }

    return 0;

}
