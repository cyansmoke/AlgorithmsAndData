cmake_minimum_required(VERSION 3.6)
project(lab3)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(Google_tests)

set(SOURCE_FILES
        src/main.cpp
        src/Tree.cpp
        src/Node.cpp
        src/queue/QueueNode.cpp
        src/queue/Queue.cpp
        src/iterators/TreeDftIterator.cpp)

add_executable(lab3 ${SOURCE_FILES})