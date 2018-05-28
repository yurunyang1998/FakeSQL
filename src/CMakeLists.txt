find_package(BISON)
find_package(FLEX)

FLEX_TARGET(scanner scanner.l   ${CMAKE_CURRENT_BINARY_DIR}/scanner.c)
BISON_TARGET(parser parser.y    ${CMAKE_CURRENT_BINARY_DIR}/parser.c)

ADD_FLEX_BISON_DEPENDENCY(scanner parser)

ADD_EXECUTABLE(FakeSQL
        main.cpp
        ${BISON_parser_OUTPUTS}
        ${FLEX_scanner_OUTPUTS})

set(CMAKE_CXX_STANDARD 11)
