cmake_minimum_required(VERSION 3.6)
project(lab3)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES src/List.h src/List.cpp src/map.cpp src/map.h src/main.cpp src/Floyd.h)

add_executable(lab3 ${SOURCE_FILES})