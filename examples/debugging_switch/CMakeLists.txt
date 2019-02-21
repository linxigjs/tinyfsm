cmake_minimum_required(VERSION 3.5)
project(DebuggingSwitch)
set(CMAKE_CXX_STANDARD 11)

include_directories(../../include)

add_executable(DebuggingSwitch
        debugging_switch.h
        main.cpp
        )