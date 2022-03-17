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

  pthread_mutex_t ui_queue_lock;
  int process_count_in_queue = 0;
  pthread_cond_t process_buffer_empty;

  struct user_interface_inputs_struct *user_interface_inputs = (
      struct user_interface_inputs_struct *)malloc(
        sizeof(struct user_interface_inputs_struct));
  user_interface_inputs->ui_queue_lock = ui_queue_lock;
  user_interface_inputs->process_count_in_queue = &process_count_in_queue;
  user_interface_inputs->process_buffer_empty = process_buffer_empty;

  struct execution_inputs_struct *execution_inputs = (
      struct execution_inputs_struct *)malloc(
        sizeof(struct execution_inputs_struct));
  execution_inputs->ui_queue_lock = &ui_queue_lock;

  pthread_t user_interface_thread, execution_thread;
  int interface_err = pthread_create(&user_interface_thread, NULL, launch_user_interface, user_interface_inputs);
  int execution_err = pthread_create(&execution_thread, NULL, launch_execution, execution_inputs);

  if (interface_err != 0 || execution_err != 0)
  {
    fprintf(stderr, "Error creating threads");
    free(user_interface_inputs);
    free(execution_inputs);
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
    free(user_interface_inputs);
    free(execution_inputs);
    free(ui_ret_val);
    free(ex_ret_val);
    return 1;
  }

  if (ui_ret_val != 0)
  {
    switch((int)(uintptr_t)ui_ret_val)
    {
      default:
        fprintf(stderr, "UI return value unknown");
      free(user_interface_inputs);
      free(execution_inputs);
      free(ui_ret_val);
      free(ex_ret_val);
      return 1;
    }
  }

  if (ex_ret_val != 0)
  {
    switch((int)(uintptr_t)ex_ret_val)
    {
      default:
        fprintf(stderr, "UI return value unknown");
      free(user_interface_inputs);
      free(execution_inputs);
      free(ui_ret_val);
      free(ex_ret_val);
      return 1;
    }
  }

  free(user_interface_inputs);
  free(execution_inputs);
  free(ui_ret_val);
  free(ex_ret_val);
  return 0;
}
