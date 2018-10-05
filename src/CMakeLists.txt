find_package(BISON)
find_package(FLEX)

message("-- Bison found version \"${BISON_VERSION}\"")
message("-- Flex found version \"${FLEX_VERSION}\"")

INCLUDE_DIRECTORIES(${CMAKE_CURRENT_BINARY_DIR})
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR})

FIND_LIBRARY(LEX_LIB l)

FLEX_TARGET(scanner scanner.l   ${CMAKE_CURRENT_BINARY_DIR}/scanner.c)
BISON_TARGET(parser parser.y    ${CMAKE_CURRENT_BINARY_DIR}/parser.c)

ADD_FLEX_BISON_DEPENDENCY(scanner parser)

ADD_EXECUTABLE(FakeSQL
        main.cpp commons.h
        ${BISON_parser_OUTPUTS}
        ${FLEX_scanner_OUTPUTS}
        ast.c ast.h
        module.c module.h
        socket.cpp socket.hpp
        netutils.cpp netutils.hpp
        epoller.cpp epoller.hpp
        thread_loop.cpp thread_loop.hpp
        hyperfine_structure.hpp
        )

set(CMAKE_CXX_STANDARD 11)
