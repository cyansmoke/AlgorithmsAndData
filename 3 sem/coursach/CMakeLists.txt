cmake_minimum_required(VERSION 3.15)
project(coursach)

set(CMAKE_CXX_STANDARD 17)


set(SOURCE_FILES
        src/main.cpp src/item.cpp src/item.h src/backpack.cpp src/backpack.h src/Constants.h)

add_executable(coursach ${SOURCE_FILES})

add_subdirectory("Google_tests")
