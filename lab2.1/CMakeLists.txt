cmake_minimum_required(VERSION 3.16)
project(lab2_1)

set(CMAKE_CXX_STANDARD 20)

add_executable(lab2_1 src/support/Map.h src/Encoder.h src/main.cpp)

add_subdirectory(Google_tests)