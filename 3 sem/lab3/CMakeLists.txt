cmake_minimum_required(VERSION 3.6)
project(lab3)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES
        src/main.cpp
        src/Tree.cpp
        src/Tree.h
        src/Node.cpp
        src/Node.h
        src/iterators/TreeDftIterator.cpp
        src/iterators/TreeDftIterator.h
        src/queue/Queue.h
        src/queue/QueueNode.h
        src/iterators/TreeBftIterator.cpp
        src/iterators/TreeBftIterator.h)

add_executable(lab3 ${SOURCE_FILES})

add_subdirectory(Google_tests)