#ifndef _COMMAND_DATA_H
#define _COMMAND_DATA_H


#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>


#include "Config.h"
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
 * 1: $ ./build/aubatch/aubatch
 * 2: $ cd ./build/aubatch/ && ./aubatch
 */


typedef struct data
{
  u_int *total;
  u_int *total_complete;
  u_int *count;
  float *turn_around_time;
  float *cpu_time;
  float *cpu_time_total;
  float *waiting_time;
  float *waiting_time_total;
  job_def *jobBuffer;
  int *buf_head;
  int *buf_tail;
  u_int *expected_waiting_time;
  pthread_cond_t *process_buffer_full;
  int *policy;
  int *is_run;
  int *is_scheduled;
} command_data_struct;


int get_command_data(command_data_struct *command_data);


#endif
