//
// Created by falleuion on 9/30/18.
//

#include <cstdlib>
#include "ast.h"
#include <iostream>

// TODO: Implementing the unit testint of the `ast.h' file.
// unit test should be added below.

void print_OprtInfo(struct _oprt_node *ref)
{
    switch (ref->type_) {
        case CREATE:
            std::cout << "operator: CREATE" << std::endl;
            break;
        case INSERT:
            std::cout << "operator: INSERT" << std::endl;
            break;
    }
    
    // TODO: taikunle ...suanle ,,,mingtianxie ....
}

int main()
{
    
    return 0;
}
