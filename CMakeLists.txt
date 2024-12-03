cmake_minimum_required(VERSION 3.10)
project(renaapa VERSION 0.0.1 LANGUAGES CXX)

option(RENAAPA_BUILD_TEST "Enable & build tests" ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(LIBRARY_OUTPUT_PATH "${CMAKE_BINARY_DIR}/${CMAKE_BUILD_TYPE}")
set(EXECUTABLE_OUTPUT_PATH "${CMAKE_BINARY_DIR}/${CMAKE_BUILD_TYPE}")

set(RENAAPA_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)

add_subdirectory(${CMAKE_SOURCE_DIR}/src)

if(${RENAAPA_BUILD_TEST})
    enable_testing()
    add_subdirectory(${CMAKE_SOURCE_DIR}/test)
endif()
