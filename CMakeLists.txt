cmake_minimum_required(VERSION 4.4.3)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(RTX VERSION 0.1)

set(CMAKE_CXX_STANDARD 20)

add_library(tuples src/tuples.cpp)
target_include_directories(tuples PUBLIC include)

add_executable(main app/main.cpp)
target_link_libraries(main PRIVATE tuples)

add_executable(projectiles app/projectiles.cpp)
target_link_libraries(projectiles PRIVATE tuples)
