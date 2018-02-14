#include <iostream>
#include "parser.h"

void test_func(utils::Parser &p)
{
    if(p.check_accept())
        std::cout << "Accept!" << std::endl;
    else
        std::cout << "Error!" << std::endl;
}

int main(int argc, const char *argv[])
{
    using utils::Parser;

    Parser p("SELEC");
    Parser p1("SELECT");
    test_func(p);
    test_func(p1);
}
