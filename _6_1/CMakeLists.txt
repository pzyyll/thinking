cmake_minimum_required(VERSION 3.7)
project(_6_1)

ADD_DEFINITIONS(-DFILEINPUT)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp)
add_executable(_6_1 ${SOURCE_FILES})