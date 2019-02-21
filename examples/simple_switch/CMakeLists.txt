cmake_minimum_required(VERSION 3.5)
project(SimpleSwitch)
set(CMAKE_CXX_STANDARD 11)

include_directories(../../include)

add_executable(SimpleSwitch
        simple_switch.h
        main.cpp
        )