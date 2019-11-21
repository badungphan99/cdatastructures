cmake_minimum_required(VERSION 3.15)
project(cdatastructures)

set(CMAKE_CXX_STANDARD 14)

include_directories(libcdatastructures)

link_directories(libcdatastructures)

add_executable(cdatastructures main.cpp)

add_executable(dsarraylist src/dsarraylist.c libcdatastructures/dsarraylist.c libcdatastructures/dsarraylist.h libcdatastructures/dscompareint.c libcdatastructures/dscompareint.h)