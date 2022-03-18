#ifndef _COMMAND_DATA_H
#define _COMMAND_DATA_H


#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>


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


typedef struct data
{
  u_int total;
  u_int *count;
  float turn_around_time;
  float cpu_time;
  float waiting_time;
} command_data_struct;


int get_command_data(command_data_struct *command_data);


#endif
