cmake_minimum_required(VERSION 3.20)
project(DataStruct C)

set(CMAKE_C_STANDARD 99)

add_executable(DataStruct main.c)
add_executable(chapter01_test chapter01/LinkList.c)
add_executable(chapter03_test chapter03/NodeTest.c)
