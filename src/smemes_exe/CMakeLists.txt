set(SMEMES_EXE_SRCS
    ${CMAKE_CURRENT_LIST_DIR}/main.cpp
)

add_executable(smemes_exe ${SMEMES_EXE_SRCS})

target_include_directories(smemes_exe PRIVATE ${PROJECT_SOURCE_DIR}/src/processor)

target_link_libraries(smemes_exe PUBLIC processor)