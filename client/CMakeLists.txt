cmake_minimum_required(VERSION 3.6)
project(client)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.c TestVariadic.c TestVariadic.h)
add_library(libstatic STATIC IMPORTED)
include_directories(BEFORE ../libstatic/include)
add_executable(client ${SOURCE_FILES})
target_link_libraries(client /home/vagrant/reproduce_static_dependency_crash/build_static/libunuseful.a)
