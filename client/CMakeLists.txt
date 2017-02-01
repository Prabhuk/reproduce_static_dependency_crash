cmake_minimum_required(VERSION 3.6)
project(client)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp)
set(CMAKE_C_COMPILER clang)
set(CMAKE_CXX_COMPILER clang++)
add_library(libstatic STATIC IMPORTED)
include_directories(BEFORE /Users/prabhu/CLionProjects/built_libs/include)
add_executable(client ${SOURCE_FILES})
target_link_libraries(client /Users/prabhu/CLionProjects/built_libs/lib/libunuseful.a)
