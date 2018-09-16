cmake_minimum_required(VERSION 3.8)
project(FakeSQL)

ADD_SUBDIRECTORY(src bin)
ADD_SUBDIRECTORY(save_store)

set(CMAKE_CXX_STANDARD 11)

