cmake_minimum_required(VERSION 3.29)
project(Project_2_Memory_Hierarchy_Simulator)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Project_2_Memory_Hierarchy_Simulator
    FileManager.cpp
    FileManager.h
    main.cpp
    memory.cpp
    Memory.h
    Simulator.cpp
    simulator.h
        main.cpp)
