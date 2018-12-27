cmake_minimum_required(VERSION 3.0)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")
set(CMAKE_INSTALL_NAME_DIR build)

project("Group Augmentation")

add_executable(
        debug_program

        src/main.cpp
        src/Configuration.h
        src/Individual.h
        src/Individual.cpp src/classes.h)