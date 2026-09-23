cmake_minimum_required(VERSION 4.4.3)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.17.0.zip)
FetchContent_MakeAvailable(googletest)

project(RTX VERSION 0.1)

add_library(tuples src/tuples.cpp)
target_include_directories(tuples PUBLIC include)

add_executable(main app/main.cpp)
target_link_libraries(main PRIVATE tuples)

add_executable(projectiles app/projectiles.cpp)
target_link_libraries(projectiles PRIVATE tuples)

# GoogleTest Unit Tests
enable_testing()
add_executable(chapter_test tests/chapter_tests/chapter_01_tuples_test.cc)
target_link_libraries(chapter_test PRIVATE tuples GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(chapter_test)
