set(UTILS_SOURCE
    ${CMAKE_CURRENT_LIST_DIR}/types.cpp
)
set(UTILS_HEADERS
    ${CMAKE_CURRENT_LIST_DIR}/types.h
)

set (CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

add_library(utils SHARED ${UTILS_HEADERS} ${UTILS_SOURCE})

target_include_directories(utils PUBLIC ${CMAKE_CURRENT_LIST_DIR})