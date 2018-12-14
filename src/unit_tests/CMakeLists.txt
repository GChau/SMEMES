set(UNIT_TEST_SRCS
    ${CMAKE_CURRENT_LIST_DIR}/main.cpp
    ${CMAKE_CURRENT_LIST_DIR}/processor_test.cpp
)

set(UNIT_TEST_HEADERS
    ${CMAKE_CURRENT_LIST_DIR}/stdafx.h
)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

add_executable(unit_test ${UNIT_TEST_SRCS} ${UNIT_TEST_HEADERS})

set_property(TARGET unit_test PROPERTY CXX_STANDARD 17)
set_property(TARGET unit_test PROPERTY CXX_STANDARD_REQUIRED ON)

target_include_directories(unit_test PRIVATE ${PROJECT_SOURCE_DIR}/src/processor)
target_include_directories(unit_test PRIVATE ${PROJECT_SOURCE_DIR}/dep/catch)

target_link_libraries(unit_test PUBLIC processor)