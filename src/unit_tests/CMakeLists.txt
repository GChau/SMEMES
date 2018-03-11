set(UNIT_TEST_SRCS
    ${CMAKE_CURRENT_LIST_DIR}/main.cpp
)


set(UNIT_TEST_HEADERS
    ${CMAKE_CURRENT_LIST_DIR}/stdafx.h
)

add_executable(unit_test ${UNIT_TEST_SRCS} ${UNIT_TEST_HEADERS})

target_include_directories(unit_test PRIVATE ${PROJECT_SOURCE_DIR}/src/processor)

target_link_libraries(unit_test PUBLIC processor)