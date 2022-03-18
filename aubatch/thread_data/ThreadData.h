#ifndef _THREAD_DATA_H
#define _THREAD_DATA_H


#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>


#include "Config.h"


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
 * 1: $ ./build/aubatch/aubatch <file_name>
 * 2: $ cd ./build/aubatch/ && ./aubatch <file_name>
 */


typedef struct jd
{
  char name[50];
  int priority;
  int burst;
  int position;
  time_t arrival;
} job_def;

typedef struct t_data
{
  pthread_mutex_t ui_queue_lock;
  int *process_count_in_queue;
  pthread_cond_t process_buffer_empty;
  int **exit_cmd;
  job_def jobBuffer[MAX_PROCESS_COUNT - 1];
  u_int buf_tail;
} thread_data_struct;


int get_thread_data(thread_data_struct *thread_data);


#endif
