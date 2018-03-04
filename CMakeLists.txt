cmake_minimum_required (VERSION 3.9)

project (smemes)

# The version number.
set (SMEMES_VERSION_MAJOR 0)
set (SMEMES_VERSION_MINOR 1)


# configure a header file to pass some of the CMake settings
# to the source code
configure_file (
  "${PROJECT_SOURCE_DIR}/src/smemes_config.h.in"
  "${PROJECT_BINARY_DIR}/smemes_config.h"
)

# add the binary tree to the search path for include files
# so that we will find smemes_config.h
include_directories("${PROJECT_BINARY_DIR}")

set (CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

add_subdirectory(${PROJECT_SOURCE_DIR}/src/processor)
add_subdirectory(${PROJECT_SOURCE_DIR}/src/smemes_exe)
