#include <iostream>
#include "module.h"

int main(int argc, const char *argv[])
{
    module *mod;
    int i, res;

    mod = new_module_from_string("(add 1 2 (\"test\" 3 4) 5)");
    res = parse_module(mod);
    delete_module(mod);
    return res;
}
