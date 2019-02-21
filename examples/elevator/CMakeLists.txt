cmake_minimum_required(VERSION 3.5)
project(Elevator)
set(CMAKE_CXX_STANDARD 11)

include_directories(../../include)

add_executable(Elevator
        elevator.cpp
        elevator.hpp
        fsmlist.hpp
        main.cpp
        motor.cpp
        motor.hpp
        )