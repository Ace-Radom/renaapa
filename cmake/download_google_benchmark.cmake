set(BENCHMARK_ENABLE_GTEST_TESTS OFF)
set(BENCHMARK_ENABLE_INSTALL OFF)
set(BENCHMARK_ENABLE_TESTING OFF)
if(CMAKE_VERSION VERSION_GREATER_EQUAL "3.24.0")
    cmake_policy(SET CMP0010 "NEW")
    cmake_policy(SET CMP0135 "NEW")
endif()
include(FetchContent)
FetchContent_Declare(benchmark
    URL https://github.com/google/benchmark/archive/refs/tags/v1.9.1.tar.gz
    URL_HASH SHA256=32131c08ee31eeff2c8968d7e874f3cb648034377dfc32a4c377fa8796d84981
    USES_TERMINAL_DOWNLOAD TRUE
)
FetchContent_MakeAvailable(benchmark)
# download and unpack google benchmark 1.9.1 src package
