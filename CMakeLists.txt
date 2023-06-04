# Set CMAKE version
cmake_minimum_required(VERSION 3.22.1)

# Project config
project(brick_breaker
    VERSION 0.1.0
    DESCRIPTION "An Atari Breakout clone."
    LANGUAGES CXX)

# Set C++ options
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# Set project paths
set(SOURCE_CODE_DIR ${PROJECT_SOURCE_DIR}/src)
set(TESTS_DIR ${PROJECT_SOURCE_DIR}/tests)
set(INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
set(DATA_DIR ${PROJECT_SOURCE_DIR}/data)

# Includes
include(CTest)
include(FetchContent)

enable_testing()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

# Move level files to build
file(GLOB LEVELS ${DATA_DIR}/levels/*.lvl)
file(COPY ${LEVELS} DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/levels/)

add_subdirectory(${SOURCE_CODE_DIR})
add_subdirectory(${TESTS_DIR})
