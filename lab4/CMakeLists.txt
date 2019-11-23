cmake_minimum_required(VERSION 3.15)
project(lab4)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES main.cpp)

add_executable(lab3 ${SOURCE_FILES})

add_subdirectory(Google_tests)