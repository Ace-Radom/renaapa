cmake_minimum_required(VERSION 3.10)
project(renaapa VERSION 0.0.1 LANGUAGES CXX)

option(RENAAPA_BUILD_BENCHMARK "Enable & build benchmark" OFF)
option(RENAAPA_BUILD_TEST "Enable & build tests" OFF)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(LIBRARY_OUTPUT_PATH "${CMAKE_BINARY_DIR}/${CMAKE_BUILD_TYPE}")
set(EXECUTABLE_OUTPUT_PATH "${CMAKE_BINARY_DIR}/${CMAKE_BUILD_TYPE}")

set(RENAAPA_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)

add_subdirectory(${PROJECT_SOURCE_DIR}/src)

if(${RENAAPA_BUILD_TEST})
    include(${PROJECT_SOURCE_DIR}/cmake/add_test_executable.cmake)
    enable_testing()
    add_subdirectory(${PROJECT_SOURCE_DIR}/test)
endif()

if(${RENAAPA_BUILD_BENCHMARK})
    include(${PROJECT_SOURCE_DIR}/cmake/download_google_benchmark.cmake)
    include(${PROJECT_SOURCE_DIR}/cmake/add_benchmark_executable.cmake)
    add_subdirectory(${PROJECT_SOURCE_DIR}/benchmark)
endif()
