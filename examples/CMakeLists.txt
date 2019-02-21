cmake_minimum_required(VERSION 3.5)
project(Examples)
set(CMAKE_CXX_STANDARD 11)

include_directories(../include)

add_subdirectory(api)
add_subdirectory(elevator)