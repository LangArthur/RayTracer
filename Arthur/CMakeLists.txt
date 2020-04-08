cmake_minimum_required(VERSION 3.13)
set(CMAKE_CXX_STANDARD 17)
project(RayTracer)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup(TARGETS)

set(CMAKE_CXX_FLAGS "-W -Wall -fprofile-arcs -ftest-coverage")

## General sources
set(SRC
)

## Include headers to program
include_directories(
    src
)

add_executable(RayTracer
    ${SRC}
    ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
)

set (SRC_TEST
    tests/main.cpp
)

## including google test library
include(GoogleTest)
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ../tests)

## Creating executable of unit tests
add_executable(unit_tests
    ${SRC}
    ${SRC_TEST}
)

## Linking libraries
target_link_libraries(RayTracer PUBLIC
    ${CMAKE_DL_LIBS}
)

target_link_libraries(unit_tests PUBLIC
    CONAN_PKG::gtest
    ${CMAKE_THREAD_LIBS_INIT}
    ${CMAKE_DL_LIBS}
)