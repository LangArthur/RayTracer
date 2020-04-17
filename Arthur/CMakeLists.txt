cmake_minimum_required(VERSION 3.13)
set(CMAKE_CXX_STANDARD 17)
project(RayTracer)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup(TARGETS)

if(UNIX)
    find_package(Threads)
    add_compile_options(-g)
endif()

##find opencv
find_package( OpenCV REQUIRED )

## Enable Google test library
enable_testing()

set(CMAKE_CXX_FLAGS "-W -Wall -fprofile-arcs -ftest-coverage")

## Primitives src
set(SRC_PRIMITIVES
    ${CMAKE_CURRENT_SOURCE_DIR}/src/primitives/Triangle.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/primitives/Square.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/primitives/Sphere.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/primitives/Plan.cpp
)

## General sources
set(SRC
    ${SRC_PRIMITIVES}
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Ray.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Scene.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Renderer.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Camera.cpp
)

## Include headers to program
include_directories(
    src/primitives
    src/utils
    src
    $ENV{EIGEN3_INCLUDE_DIR}
)

## Compile sources
add_executable(RayTracer
    ${SRC}
    ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
)

## Test sources
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

## Linking libraries to executable
target_link_libraries(RayTracer PUBLIC
    CONAN_PKG::eigen
    CONAN_PKG::opencv
    ${CMAKE_DL_LIBS}
)

## Linking libraries to street
target_link_libraries(unit_tests PUBLIC
    CONAN_PKG::eigen
    CONAN_PKG::opencv
    CONAN_PKG::gtest
    ${CMAKE_THREAD_LIBS_INIT}
    ${CMAKE_DL_LIBS}
)