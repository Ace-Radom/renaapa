add_library(renaapa SHARED
    ${CMAKE_CURRENT_SOURCE_DIR}/digit.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/lint.cpp
)
target_include_directories(renaapa
    PUBLIC
        ${RENAAPA_INCLUDE_DIR}
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
)
target_compile_definitions(renaapa
    PRIVATE
        __RENALIBS_EXPORT__
)
