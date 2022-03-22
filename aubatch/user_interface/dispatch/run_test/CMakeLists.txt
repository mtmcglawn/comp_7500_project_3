cmake_minimum_required(VERSION 3.22)
include_guard(GLOBAL)

set(CURRENT_DIR RUN_TEST)
set(CLASS_NAME RunTest)
set(DRIVER_NAME ${CLASS_NAME}Driver)
set(EXE_NAME run_test)


if (NOT ${CMAKE_SOURCE_DIR})
    #######################################
    # Project setup
    #######################################
    set(PROJECT_NAME ${EXE_NAME})
    project(${PROJECT_NAME})
    # After project(..) is called, the following variables are availble:
    # * PROJECT_SOURCE_DIR - Top level source directory for the project
    # * PROJECT_BINARY_DIR - Full path to build directory for project

    find_package(Git QUIET)

    execute_process(COMMAND ${GIT_EXECUTABLE} rev-parse --show-toplevel
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
        OUTPUT_VARIABLE BASE_DIR
        OUTPUT_STRIP_TRAILING_WHITESPACE
        )

    include(${BASE_DIR}/cmake/cmake_includes.cmake)

endif()

#######################################
# Add Subdirectories
#######################################
#add_subdirectory(${})


#######################################
# Add other directories
#######################################
if(${CMAKE_SOURCE_DIR} STREQUAL ${${CURRENT_DIR}_INC})
    #Add Includes to directories not in subdirectories
    add_subdirectory(${COMMAND_DATA_DIR} ${BUILD_DIR}/command_data)
    add_subdirectory(${THREAD_DATA_DIR} ${BUILD_DIR}/thread_data)
    add_subdirectory(${BEGIN_RUN_DIR} ${BUILD_DIR}/begin_run)
endif()


#######################################
# Define include directories
#######################################
include_directories(${COMMON_INCLUDES} ${${CURRENT_DIR}_INC}
    #Add additional required .h files here
    ${COMMAND_DATA_INC}
    ${THREAD_DATA_INC}
    ${BEGIN_RUN_INC}
    ${RUN_FCFS_INC}
    ${RUN_SJF_INC}
    ${RUN_PRIORITY_INC}
    )


#######################################
# Source files
#######################################
file(GLOB SRC_FILES ${${CURRENT_DIR}_DIR}/*.c
    #Add additional required .c files here
    )

#######################################
# Remove the driver to create a library
#######################################
list(REMOVE_ITEM SRC_FILES ${${CURRENT_DIR}_DIR}/${DRIVER_NAME}.c)
list(REMOVE_ITEM SRC_FILES ${${CURRENT_DIR}_DIR}/${CLASS_NAME}_fake.c)
# Key idea: SEPARATE OUT your main() function into its own file so it can be its
# own executable. Separating out main() means you can add this library to be
# used elsewhere (e.g., linking to the test executable).


#######################################
# Compile source files into a library
#######################################
add_library(${CLASS_NAME}_lib SHARED ${SRC_FILES})


#######################################
# linking the library
#######################################
target_link_libraries(${CLASS_NAME}_lib PUBLIC
    #Add Libraries that need to be linked in
    ${COMMAND_DATA_LIB}
    ${THREAD_DATA_LIB}
    ${BEGIN_RUN_LIB}
    ${RUN_FCFS_LIB}
    ${RUN_SJF_LIB}
    ${RUN_PRIORITY_LIB}
    )


#######################################
# Main is separate (e.g., library client)
#######################################
#add_executable(${EXE_NAME} ${${CURRENT_DIR}_DIR}/${DRIVER_NAME}.c)


#######################################
# linking Main against the library
#######################################
#target_link_libraries(${EXE_NAME} PUBLIC ${CLASS_NAME}_lib)


if(ENABLE_TESTS)
    #######################################
    # Testing
    #######################################
    # Options. Turn on with 'cmake -Dmyvarname=ON'.
    # option(BUILD_TESTS "Build all tests." ON) # Makes boolean 'test' available.
    enable_testing()

    # Include the gtest library. gtest_SOURCE_DIR is available due to
    # including the googletest external directory.
    include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})


    #######################################
    # Test files
    #######################################
    # file(GLOB TEST_SRC_FILES ${PROJECT_SOURCE_DIR}/test/*.cpp)
    set(TEST_SRC_FILES
        ${${CURRENT_DIR}_DIR}/${CLASS_NAME}_test.cpp
        )
    set(TEST_LIB_SRC_FILES
        ${${CURRENT_DIR}_DIR}/${CLASS_NAME}_fake.c
        )


    #######################################
    # Compile fake source files into a library
    #######################################
    add_library(${CLASS_NAME}_fake_lib SHARED ${TEST_LIB_SRC_FILES})


    #######################################
    # Compile empty source files into a library for testing
    #######################################
    add_library(${CLASS_NAME}_empty_lib SHARED ${SRC_FILES})


    #######################################
    # linking the empty test library
    #######################################
    target_link_libraries(${CLASS_NAME}_empty_lib PUBLIC
        #Add Fake versions of Libs required
	${COMMAND_DATA_FAKE_LIB}
	${THREAD_DATA_FAKE_LIB}
	${BEGIN_RUN_FAKE_LIB}
        ${RUN_FCFS_LIB}
	${RUN_SJF_FAKE_LIB}
	${RUN_PRIORITY_FAKE_LIB}
        )


    #######################################
    # Unit Tests
    #######################################
    add_executable(${EXE_NAME}_test.exe ${TEST_SRC_FILES})


    #######################################
    # Standard linking to gtest stuff
    #######################################
    target_link_libraries(${EXE_NAME}_test.exe gtest gtest_main)


    #######################################
    # Extra linking for the project.
    #######################################
    target_link_libraries(${EXE_NAME}_test.exe ${CLASS_NAME}_empty_lib
        )


    # This is so you can do 'make test' to see all your tests run, instead of
    # manually running the executable *_tests.exe to see those specific tests.
    # Allows for running tests of current directory only in current directory
    # or from the root of the repository
    if(${CMAKE_SOURCE_DIR} STREQUAL ${BASE_DIR}
            OR ${CMAKE_SOURCE_DIR} STREQUAL ${${CURRENT_DIR}_DIR})
        add_test(${EXE_NAME}Tests ${EXE_NAME}_test.exe)
    endif()
endif()
