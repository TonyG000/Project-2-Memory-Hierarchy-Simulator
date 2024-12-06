cmake_minimum_required(VERSION 3.26)
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
        cache.cpp
        cache.h
        cacheline.h
        cachline.cpp
)  # Add the missing Cache.cpp file
# Link necessary libraries (if any, e.g., pthread)
target_link_libraries(Project_2_Memory_Hierarchy_Simulator)