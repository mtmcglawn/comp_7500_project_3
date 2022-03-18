#define _EXECUTION_C
#include "Execution.h"


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


void *launch_execution(void *arg)
{
  pthread_exit((void *)(intptr_t)run_execution((thread_data_struct*)arg));
}

int run_execution(thread_data_struct *execution_inputs)
{
  char arg1[50];
  char arg2[50];
  pthread_mutex_t ui_queue_lock = execution_inputs->ui_queue_lock;
  int *process_count_in_queue = execution_inputs->process_count_in_queue;
  pthread_cond_t process_buffer_empty = execution_inputs->process_buffer_empty;
  int **exit_cmd = (int **)malloc(sizeof(int));
  exit_cmd = execution_inputs->exit_cmd;
  job_def *jobBuffer = execution_inputs->jobBuffer;
  u_int buf_tail = execution_inputs->buf_tail;
  pthread_mutex_lock(&ui_queue_lock);
  while (**exit_cmd != 0)
  {
    while (**exit_cmd != 0 && *process_count_in_queue == 0)
    {
      pthread_cond_wait(&process_buffer_empty, &ui_queue_lock);
    }
    sprintf(arg1, "%s", jobBuffer[buf_tail].name);
    sprintf(arg2, "%u", jobBuffer[buf_tail].burst);
    time_t start_wait = jobBuffer[buf_tail].arrival;
    int burst = jobBuffer[buf_tail].burst;
    time_t start_time = time(NULL);
    pid_t pid = fork();
    if (pid == 0)
    {
      execv("echo hello", (char*[]){"echo hello", arg1, arg2, NULL});
    }

    pthread_mutex_unlock(&ui_queue_lock);
  }
  return 0;
}
