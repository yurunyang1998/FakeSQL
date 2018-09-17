cmake_minimum_required(VERSION 3.8)
project(the_new_fake_sql)

find_package(libbson-1.0)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp B-tree_nodes.hpp B-tree-initial.hpp pub_friends.hpp file_read_write_system.h file_read_write_system.cpp)
add_executable(the_new_fake_sql ${SOURCE_FILES})

target_include_directories (the_new_fake_sql PRIVATE ${BSON_INCLUDE_DIRS})
target_link_libraries (the_new_fake_sql PRIVATE ${BSON_LIBRARIES})
target_compile_definitions (the_new_fake_sql PRIVATE ${BSON_DEFINITIONS})