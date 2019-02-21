cmake_minimum_required(VERSION 3.5)
project(MultipleSwitch)
set(CMAKE_CXX_STANDARD 11)

include_directories(../../include)

add_executable(MultipleSwitch
        multiple_switch.h
        main.cpp
        )