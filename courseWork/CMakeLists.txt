cmake_minimum_required(VERSION 3.6)
project(lab3)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES src/List.h src/main.cpp src/Flow.cpp src/Flow.h src/map.h src/map.cpp)

add_executable(lab3 ${SOURCE_FILES})

add_subdirectory(Google_tests)