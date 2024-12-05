function(add_benchmark_executable BENCHMARK_TARGET_SRC)
    add_executable(${BENCHMARK_TARGET_SRC}
        ${CMAKE_CURRENT_SOURCE_DIR}/${BENCHMARK_TARGET_SRC}.cpp
    )
    target_include_directories(${BENCHMARK_TARGET_SRC}
        PUBLIC
            ${RENAAPA_INCLUDE_DIR}
        PRIVATE
            ${BENCHMARK_SOURCE_DIR}/include
    )
    target_link_libraries(${BENCHMARK_TARGET_SRC}
        renaapa
        benchmark::benchmark
    )
endfunction()
