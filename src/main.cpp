#include <iostream>
#include "module.h"
#include "socket.hpp"

int main(int argc, const char *argv[])
{
    module *mod;
    int res;
    char demo[] = "select a form z;";

    mod = new_module_from_string(demo);
    res = parse_module(mod);
    delete_module(mod);
    return res;

}
