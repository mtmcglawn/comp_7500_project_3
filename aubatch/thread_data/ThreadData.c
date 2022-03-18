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
 * 1: $ ./build/pwordcount/pwordcount <file_name>
 * 2: $ cd ./build/pwordcount/ && ./pwordcount <file_name>
 */


int get_thread_data(thread_data_struct *thread_data)
{
  pthread_mutex_t ui_queue_lock;
  int process_count_in_queue = 0;
  pthread_cond_t process_buffer_empty;
  u_int count = 0;
  int exit = -1;
  int *exit_ptr = malloc(sizeof(int));
  exit_ptr = &exit;

  thread_data->ui_queue_lock = ui_queue_lock;
  thread_data->process_count_in_queue = &process_count_in_queue;
  thread_data->process_buffer_empty = process_buffer_empty;
  thread_data->exit_cmd = malloc(sizeof(int));
  thread_data->exit_cmd = &exit_ptr;


  return 0;
}
