cmake_minimum_required(VERSION 3.22)
project(Clion)

set(CMAKE_CXX_STANDARD 14)

#find_package(Boost 1.78.0 COMPONENTS unit_test_framework REQUIRED)
#include_directories(${Boost_INCLUDE_DIRS})

add_executable(Clion Decorator.cpp)
