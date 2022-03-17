#ifndef _USER_INTERFACE_H
#define _USER_INTERFACE_H


#include <pthread.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>


#include "Config.h"
#include "Dispatch.h"
#include "Get_Input.h"


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


typedef struct user_interface_inputs_struct
{
  pthread_mutex_t ui_queue_lock;
  int *process_count_in_queue;
  pthread_cond_t process_buffer_empty;
} user_interface_inputs;


void *launch_user_interface(void *arg);

int run_user_interface(struct user_interface_inputs_struct *user_interface_inputs);


#endif
