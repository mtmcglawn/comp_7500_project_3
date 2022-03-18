#ifndef _USER_INTERFACE_H
#define _USER_INTERFACE_H


#include <pthread.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>


#include "CommandData.h"
#include "Config.h"
#include "Dispatch.h"
#include "Get_Input.h"
#include "ThreadData.h"


/*
 * COMP 7500/001
 * Matthew Tyler McGlawn
 * Auburn University
 *
 * COMPILE
 *
 * 2 ways:
 * 1: $ ./build.sh
 * 2: $ mkdir build && cd build && cmake .. && cmake --build .
 *
 * Either way may be used
 * 
 *
 * TESTS
 *
 * To run tests in any directory with source code:
 * - googletest must be located in repository - run
 *
 *   `git submodule update --init`
 *
 *    to clone googletest into appropriate location
 *
 * First build, then either:
 * 1. $ cd build && ctest
 * 2. $ ./build.sh test
 *
 *
 * USE
 *
 * To run the program you can either:
 * 1: $ ./build/pwordcount/pwordcount <file_name>
 * 2: $ cd ./build/pwordcount/ && ./pwordcount <file_name>
 */


void *launch_user_interface(void *arg);

int run_user_interface(thread_data_struct *user_interface_inputs);


#endif
