cmake_minimum_required(VERSION 3.8)
project(the_new_fake_sql)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp B-tree_nodes.hpp B-tree-initial.hpp pub_friends.hpp)
add_executable(the_new_fake_sql ${SOURCE_FILES})