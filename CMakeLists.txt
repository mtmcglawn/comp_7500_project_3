cmake_minimum_required(VERSION 3.22)
include_guard(GLOBAL)

#######################################
# Project setup
#######################################
set(PROJECT_NAME Project_3)
set(PROJECT_VERSION 1.0.0)
project(${PROJECT_NAME} VERSION ${PROJECT_VERSION})
# After project(..) is called, the following variables are availble:
# * PROJECT_SOURCE_DIR - Top level source directory for the project
# * PROJECT_BINARY_DIR - Full path to build directory for project


#######################################
# Set up the paths
#######################################
set(BASE_DIR ${CMAKE_SOURCE_DIR})
include(${BASE_DIR}/cmake/cmake_includes.cmake)


#######################################
# Allow testing
#######################################
if(ENABLE_TESTS)
	enable_testing()
endif()


#######################################
# Add External Dependencies
#######################################
add_subdirectory(${EXTERNAL_DEPS_DIR})

#######################################
# Add Subdirectories
#######################################
add_subdirectory(${AU_BATCH_DIR})
