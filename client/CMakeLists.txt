cmake_minimum_required(VERSION 3.6)
project(client)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp)
add_library(libstatic STATIC IMPORTED)
include_directories(BEFORE /home/vagrant/reproduce_static_dependency_crash/built_libs/include)
add_executable(client ${SOURCE_FILES})
target_link_libraries(client /home/vagrant/reproduce_static_dependency_crash/built_libs/lib/libunuseful.a)
