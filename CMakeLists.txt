cmake_minimum_required(VERSION 3.22)
project(DesignPattern)

set(CMAKE_CXX_STANDARD 14)

add_executable(DesignPattern
        Decorator/Decorator.cpp
        Strategy/main.cpp)
