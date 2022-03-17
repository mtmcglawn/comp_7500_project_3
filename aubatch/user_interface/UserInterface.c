#define _USER_INTERFACE_C
#include "UserInterface.h"


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


void *launch_user_interface(void *arg)
{
  pthread_exit((void *)(intptr_t)run_user_interface((struct user_interface_inputs_struct*)arg));
}

int run_user_interface(struct user_interface_inputs_struct *user_interface_inputs)
{
  pthread_mutex_t ui_queue_lock = user_interface_inputs->ui_queue_lock;
  int *process_count_in_queue = user_interface_inputs->process_count_in_queue;
  pthread_cond_t process_buffer_empty= user_interface_inputs->process_buffer_empty;
  int *exit_cmd = malloc(sizeof(int));
  *exit_cmd = 0;
  int *err_rcvd = malloc(sizeof(int));
  err_rcvd = 0;
  size_t input_size[INPUT_BUFFER_MAX_SIZE];
  char *input = (char *)malloc(10 * sizeof(char));
  while (*exit_cmd == 0)
  {
    pthread_mutex_lock(&ui_queue_lock);
    while (*process_count_in_queue == MAX_PROCESS_COUNT)
    {
      pthread_cond_wait(&process_buffer_empty, &ui_queue_lock);
    }
    pthread_mutex_unlock(&ui_queue_lock);
    fprintf(stdout, "\n>");
    get_user_interface_input(input, input_size);
    //exit_cmd = 1;
    dispatch(input, &exit_cmd, &err_rcvd);
  }
  int ret_val = (int)(uintptr_t)err_rcvd;
  return ret_val;
}
