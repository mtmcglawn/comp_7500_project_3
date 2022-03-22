#define _THREAD_DATA_C
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


int get_thread_data(thread_data_struct *thread_data)
{
  u_int process_count_in_queue = 0;
  int buf_tail = 0;
  int buf_head = 0;
  pthread_cond_t process_buffer_full;
  pthread_cond_t process_buffer_empty;
  int exit = -1;
  int *exit_ptr = malloc(sizeof(int));
  exit_ptr = &exit;
  float cpu_time = 0.0;
  float cpu_time_total = 0.0;
  u_int expected_waiting_time = 0;
  float waiting_time = 0.0;
  float waiting_time_total = 0.0;
  float turn_around_time = 0.0;
  float turn_around_time_total = 0.0;

  thread_data->process_count_in_queue = &process_count_in_queue;
  thread_data->buf_tail = &buf_tail;
  thread_data->buf_head = &buf_head;
  thread_data->process_buffer_full = &process_buffer_full;
  thread_data->process_buffer_empty = &process_buffer_empty;
  thread_data->exit_cmd = malloc(sizeof(int));
  thread_data->exit_cmd = &exit;
  thread_data->cpu_time = &cpu_time;
  thread_data->cpu_time_total = &cpu_time_total;
  thread_data->expected_waiting_time = &expected_waiting_time;
  thread_data->waiting_time = &waiting_time;
  thread_data->waiting_time_total = &waiting_time_total;
  thread_data->turn_around_time = &turn_around_time;
  thread_data->turn_around_time_total = &turn_around_time_total;

  return 0;
}
