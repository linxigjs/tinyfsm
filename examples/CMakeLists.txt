cmake_minimum_required(VERSION 3.5)
project(Examples)
set(CMAKE_CXX_STANDARD 11)

include_directories(../include)

add_subdirectory(debugging_switch)
add_subdirectory(elevator)
add_subdirectory(mealy_machine)
add_subdirectory(moore_machine)
add_subdirectory(multiple_switch)
add_subdirectory(resetting_switch)
add_subdirectory(simple_switch)
