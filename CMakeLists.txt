cmake_minimum_required(VERSION 3.9)
project(group_augmentation_cpp)

set(CMAKE_CXX_STANDARD 11)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++ -static-libgcc")

set(SOURCE_FILES main.cpp)
add_executable(group_augmentation_cpp main.cpp)