cmake_minimum_required(VERSION 3.8)
project(FakeSQL)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Btree_leaf_node.h Btree_zhongjian_node.h .idea/Btree_leaf_node.cpp .idea/Btree_zhongjian_node.cpp)
add_executable(FakeSQL ${SOURCE_FILES})