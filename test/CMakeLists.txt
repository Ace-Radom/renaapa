add_executable(test_lint_value_init_get
    ${CMAKE_CURRENT_SOURCE_DIR}/test_lint_value_init_get.cpp    
)
target_include_directories(test_lint_value_init_get
    PUBLIC
        ${RENAAPA_INCLUDE_DIR}
)
target_link_libraries(test_lint_value_init_get
    renaapa
)

add_test(
    NAME lint_value_init_get
    COMMAND $<TARGET_FILE:test_lint_value_init_get>
)
