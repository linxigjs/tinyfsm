cmake_minimum_required(VERSION 3.5)
project(Exam_api)
set(CMAKE_CXX_STANDARD 11)

include_directories(../../include)

add_executable(Exam_api
        debugging_switch.cpp
        mealy_machine.cpp
        moore_machine.cpp
        multiple_switch.cpp
        resetting_switch.cpp
        simple_switch.cpp
        )