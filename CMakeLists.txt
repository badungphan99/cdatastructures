cmake_minimum_required(VERSION 3.10)
project(cdatastructures)

set(CMAKE_CXX_STANDARD 14)

include_directories(libcdatastructures)

file(GLOB LIBS "libcdatastructures/*.c")

set(cdatastructures ${LIBS})

add_executable(dsarraylist src/dsarraylist.c)
target_link_libraries(dsarraylist ${cdatastructures})

add_executable(dsavltree src/dsavltree.c)
target_link_libraries(dsavltree ${cdatastructures})

add_executable(bai3 src/bai3.c)
target_link_libraries(bai3 ${cdatastructures})