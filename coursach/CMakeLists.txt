cmake_minimum_required(VERSION 3.15)
project(coursach)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory("Google_tests")

add_executable(coursach src/main.cpp)