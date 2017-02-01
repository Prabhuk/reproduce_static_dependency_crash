cmake_minimum_required(VERSION 3.6)
project(libstatic)
set(CMAKE_C_COMPILER clang)
set(CMAKE_CXX_COMPILER clang++)

set(CMAKE_CXX_STANDARD 11)
include_directories(include)
set(SOURCE_FILES src)
add_library(unuseful STATIC ${SOURCE_FILES}/Unuseful.cpp)
