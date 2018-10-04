
INCLUDE_DIRECTORIES(../src)

ADD_EXECUTABLE(unit_test
        test_ast.cpp
        ../src/ast.h
        ../src/ast.c
        ../src/module.c
        ../src/module.h
        )