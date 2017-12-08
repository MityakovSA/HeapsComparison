cmake_minimum_required(VERSION 3.8)
project(HeapsComparison)

set(CMAKE_CXX_STANDARD 11)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

set(SOURCE_FILES include/binary_heap.hpp sources/binary_heap.cpp)
set(TEST_FILES tests/catch.hpp tests/main.cpp tests/binary_build.cpp tests/binary_insert.cpp tests/binary_extractMin.cpp tests/binary_merge.cpp)
add_executable(HeapsComparison ${SOURCE_FILES} sources/main.cpp)
add_executable(Tests ${SOURCE_FILES} ${TEST_FILES})