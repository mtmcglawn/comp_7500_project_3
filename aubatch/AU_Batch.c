#define _AU_BATCH_C
#include "AU_Batch.h"


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


int aubatch()
{
  char welcome_string[60] = "Welcome to Tyler's batch job scheduler Version 1.0\n";
  char second_line[60] = "Type 'help' to find out more about AUbatch commands.\n";
  strcat( welcome_string, second_line);
  fprintf(stdout, "%s", welcome_string);

  thread_data_struct *inputs = (
      thread_data_struct *)malloc(
        sizeof(thread_data_struct));
  get_thread_data(inputs)

  pthread_t user_interface_thread, execution_thread;
  int interface_err = pthread_create(&user_interface_thread, NULL, launch_user_interface, inputs);
  int execution_err = pthread_create(&execution_thread, NULL, launch_execution, inputs);

  if (interface_err != 0 || execution_err != 0)
  {
    fprintf(stderr, "Error creating threads");
    free(inputs);
    free(inputs);
    return 1;
  }

  pthread_mutex_init(&ui_queue_lock, NULL);
  pthread_cond_init(&process_buffer_empty, NULL);

  void *ui_ret_val;
  void *ex_ret_val;
  interface_err = pthread_join(user_interface_thread, &ui_ret_val);
  execution_err = pthread_join(execution_thread, &ex_ret_val);

  if (interface_err != 0 || execution_err != 0)
  {
    fprintf(stderr, "Error joining threads");
    free(inputs);
    free(ui_ret_val);
    free(ex_ret_val);
    return 1;
  }

  if ((int)(uintptr_t)ui_ret_val != 0)
  {
    switch((int)(uintptr_t)ui_ret_val)
    {
      default:
        fprintf(stderr, "UI return value unknown");
      free(inputs);
      free(ex_ret_val);
      return 1;
    }
  }

  if ((int)(uintptr_t)ex_ret_val != 0)
  {
    switch((int)(uintptr_t)ex_ret_val)
    {
      default:
        fprintf(stderr, "UI return value unknown");
      free(inputs);
      free(ui_ret_val);
      free(ex_ret_val);
      return 1;
    }
  }

  free(inputs);
  free(ui_ret_val);
  free(ex_ret_val);
  return 0;
}
