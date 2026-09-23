cmake_minimum_required(VERSION 4.4.3)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

project(RTX VERSION 0.1)

add_library(tuples src/tuples.cpp)
target_include_directories(tuples PUBLIC include)

add_executable(main app/main.cpp)
target_link_libraries(main PRIVATE tuples)

add_executable(projectiles app/projectiles.cpp)
target_link_libraries(projectiles PRIVATE tuples)
