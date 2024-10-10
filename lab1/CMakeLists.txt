cmake_minimum_required(VERSION 3.27)
project(lab1)

set(CMAKE_CXX_STANDARD 23)

add_executable(lab1 lab1.cpp
        url_func.h
        url_func.cpp
        menu.h
        menu.cpp)
