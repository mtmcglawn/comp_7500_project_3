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
 * 1: $ ./build/aubatch/aubatch <file_name>
 * 2: $ cd ./build/aubatch/ && ./aubatch <file_name>
 */


void *launch_user_interface(void *arg)
{
  pthread_exit((void *)(intptr_t)run_user_interface(arg));
}

int run_user_interface(void *arg)
{
  thread_data_struct *user_interface_inputs = (thread_data_struct*)arg;
  int *process_count_in_queue = user_interface_inputs->process_count_in_queue;
  int *err_rcvd = (int *)malloc(sizeof(int));
  *err_rcvd = 0;
  size_t input_size[INPUT_BUFFER_MAX_SIZE];
  char *input = (char *)malloc(INPUT_BUFFER_MAX_SIZE * sizeof(char));
  command_data_struct *command_data = (
      command_data_struct *)malloc(
        sizeof(command_data_struct));
  get_command_data(command_data);
  command_data->count = user_interface_inputs->process_count_in_queue;
  command_data->jobBuffer = user_interface_inputs->jobBuffer;
  command_data->buf_head = user_interface_inputs->buf_head;
  command_data->expected_waiting_time = user_interface_inputs->expected_waiting_time;
  pthread_mutex_lock(&(user_interface_inputs->ui_queue_lock));
  while (*(user_interface_inputs->exit_cmd) != 0)
  {
    while (*process_count_in_queue == MAX_PROCESS_COUNT)
    {
      pthread_cond_wait(&(user_interface_inputs->process_buffer_full), &(user_interface_inputs->ui_queue_lock));
    }
    fprintf(stdout, "\n>");
    get_user_interface_input(&input, input_size);
    dispatch(input, user_interface_inputs->exit_cmd, &err_rcvd, command_data);
  }
  pthread_cond_signal(&(user_interface_inputs->process_buffer_empty));
  pthread_mutex_unlock(&(user_interface_inputs->ui_queue_lock));
  int ret_val = *err_rcvd;
  return ret_val;
}
