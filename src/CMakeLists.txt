find_package(BISON)
find_package(FLEX)

BISON_TARGET(parser parser.y    ${CMAKE_CURRENT_BINARY_DIR}/parser.cpp)
FLEX_TARGET(scanner scanner.l   ${CMAKE_CURRENT_BINARY_DIR}/scanner.cpp)

ADD_FLEX_BISON_DEPENDENCY(scanner parser)

ADD_EXECUTABLE(FakeSQL
        main.cpp
        parser.cpp parser.h
        fsm.cpp fsm.h
        ${BISON_parser_OUTPUTS}
        ${FLEX_scanner_OUTPUTS})

set(CMAKE_CXX_STANDARD 11)
