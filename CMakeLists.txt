#!/bin/sh

###############################################################
# MIT License
# 
# Copyright (c) 2018 Pablo Arias
# 
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
# 
# The above copyright notice and this permission notice shall be included
# in all copies or substantial portions of the Software.
# 
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
# INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
# PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
# COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
# WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF
# OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
# 
###############################################################

###############################################################
# Using https://github.com/pabloariasal/modern-cmake-sample
# Modified by gelever on April 1st, 2018 #
###############################################################

cmake_minimum_required(VERSION 3.5)
project(MY_PROJECT VERSION 1.0 LANGUAGES CXX)
enable_testing()

find_package(linalgcpp REQUIRED)

add_library(MY_PROJECT
    src/src_file.cpp
)

target_compile_options(MY_PROJECT PRIVATE $<$<CXX_COMPILER_ID:GNU>:-Wall -Wextra -Wpedantic -O3>)
target_compile_options(MY_PROJECT PRIVATE $<$<CXX_COMPILER_ID:Clang>:-Wall -Wextra -Wpedantic -O3>)

target_link_libraries(MY_PROJECT
    PUBLIC
        linalgcpp::linalgcpp
)

target_include_directories(MY_PROJECT
    PUBLIC
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
)

# Installation
include(GNUInstallDirs)
set(INSTALL_CONFIGDIR ${CMAKE_INSTALL_LIBDIR}/cmake/libMYPROJECT)

install(TARGETS MY_PROJECT
    EXPORT MY_PROJECT-targets
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

# Export targets to a script
install(EXPORT MY_PROJECT-targets
    FILE MY_PROJECTTargets.cmake
    NAMESPACE MY_PROJECT::
    DESTINATION ${INSTALL_CONFIGDIR}
)

# Create Config files
include(CMakePackageConfigHelpers)
write_basic_package_version_file(
    ${CMAKE_CURRENT_BINARY_DIR}/MY_PROJECTConfigVersion.cmake
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY AnyNewerVersion
)

configure_package_config_file(
    ${CMAKE_CURRENT_LIST_DIR}/cmake/MY_PROJECTConfig.cmake.in
    ${CMAKE_CURRENT_BINARY_DIR}/MY_PROJECTConfig.cmake
    INSTALL_DESTINATION ${INSTALL_CONFIGDIR}
)

configure_file(
    "${PROJECT_SOURCE_DIR}/config/MY_PROJECT_config.h.in"
    "${PROJECT_BINARY_DIR}/MY_PROJECT_config.h"
  )

# Install Config files
install(FILES
    ${CMAKE_CURRENT_BINARY_DIR}/MY_PROJECTConfig.cmake
    ${CMAKE_CURRENT_BINARY_DIR}/MY_PROJECTConfigVersion.cmake
    DESTINATION ${INSTALL_CONFIGDIR}
)

# Export from the build tree
export(EXPORT MY_PROJECT-targets
    FILE ${CMAKE_CURRENT_BINARY_DIR}/MY_PROJECTTargets.cmake
    NAMESPACE MY_PROJECT::
       )

   export(PACKAGE MY_PROJECT)

# Sub Directories
add_subdirectory(examples)
