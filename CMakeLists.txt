cmake_minimum_required(VERSION 3.8)
project(FakeSQL)

ADD_SUBDIRECTORY(src bin)
ADD_SUBDIRECTORY(tmp_engine)

set(CMAKE_CXX_STANDARD 11)

