function(add_test_executable TEST_TARGET_SRC)
    add_executable(${TEST_TARGET_SRC}
        ${CMAKE_CURRENT_SOURCE_DIR}/${TEST_TARGET_SRC}.cpp
    )
    target_include_directories(${TEST_TARGET_SRC}
        PUBLIC
            ${RENAAPA_INCLUDE_DIR}
    )
    target_link_libraries(${TEST_TARGET_SRC}
        renaapa
    )
    string(REGEX REPLACE "^test_" "" TEST_TARGET_NAME ${TEST_TARGET_SRC})
    add_test(
        NAME ${TEST_TARGET_NAME}
        COMMAND $<TARGET_FILE:${TEST_TARGET_SRC}>
    )
endfunction()
