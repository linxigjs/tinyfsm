cmake_minimum_required(VERSION 3.5)
project(ResettingSwitch)
set(CMAKE_CXX_STANDARD 11)

include_directories(../../include)

add_executable(ResettingSwitch
        resetting_switch.h
        main.cpp
        )