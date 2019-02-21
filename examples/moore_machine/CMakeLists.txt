cmake_minimum_required(VERSION 3.5)
project(MooreMachine)
set(CMAKE_CXX_STANDARD 11)

include_directories(../../include)

add_executable(MooreMachine
        moore_machine.h
        main.cpp
        )