cmake_minimum_required(VERSION 3.5)
project(MealyMachine)
set(CMAKE_CXX_STANDARD 11)

include_directories(../../include)

add_executable(MealyMachine
        mealy_machine.h
        main.cpp
        )