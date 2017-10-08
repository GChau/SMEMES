cmake_minimum_required (VERSION 3.9)
project (SMEMES)
# The version number.
set (SMEMES_VERSION_MAJOR 1)
set (SMEMES_VERSION_MINOR 0)

# configure a header file to pass some of the CMake settings
# to the source code
configure_file (
  "${PROJECT_SOURCE_DIR}/src/SMEMESConfig.h.in"
  "${PROJECT_BINARY_DIR}/SMEMESConfig.h"
)

# add the binary tree to the search path for include files
# so that we will find SMEMESConfig.h
include_directories("${PROJECT_BINARY_DIR}")

# add the executable
add_executable(SMEMES src/Main.cpp)
#target_link_libraries (SMEMES  ${EXTRA_LIBS})