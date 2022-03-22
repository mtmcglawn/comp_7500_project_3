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
 * 1: $ ./build/aubatch/aubatch
 * 2: $ cd ./build/aubatch/ && ./aubatch
 */


void *launch_execution(void *arg)
{
  pthread_exit((void *)(intptr_t)run_execution(arg));
}

int run_execution(void *arg)
{
  char arg1[50];
  char arg2[50];
  thread_data_struct *execution_inputs = (thread_data_struct*)arg;
  int local_exit_cmd = -1;
  while (local_exit_cmd != 0)
  {
    job_def *jobBuffer = execution_inputs->jobBuffer;
    int *buf_tail = execution_inputs->buf_tail;
    pthread_mutex_lock(execution_inputs->ui_queue_lock);
    while (*(execution_inputs->exit_cmd) != 0 && *(execution_inputs->process_count_in_queue) < 1)
    {
      pthread_cond_wait(execution_inputs->process_buffer_empty, execution_inputs->ui_queue_lock);
    }
    if (*(execution_inputs->exit_cmd) == 0)
    {
      pthread_mutex_unlock(execution_inputs->ui_queue_lock);
      return 0;
    }
    *(execution_inputs->process_count_in_queue)--;
    sprintf(arg1, "%s", jobBuffer[*buf_tail].name);
    sprintf(arg2, "%u", jobBuffer[*buf_tail].burst);
    time_t start_wait = jobBuffer[*buf_tail].arrival;
    int burst = jobBuffer[*buf_tail].burst;
    time_t start_time = time(NULL);
    pid_t pid = fork();
    if (pid == 0)
    {
      execv("/bin/echo", (char*[]){"/bin/echo", arg1, arg2, NULL});
    }
    *buf_tail++;
    if (*buf_tail == MAX_PROCESS_COUNT)
    {
      *buf_tail = 0;
    }
    pthread_cond_signal(execution_inputs->process_buffer_full);
    pthread_mutex_unlock(execution_inputs->ui_queue_lock);
    int status = 0;
    wait(&status);
    time_t finish_time = time(NULL);
    time_t run_time = finish_time - start_wait;
    time_t wait_time = start_time - start_wait;
    *(execution_inputs->cpu_time) += run_time;
    *(execution_inputs->cpu_time_total) = *(execution_inputs->cpu_time);
    *(execution_inputs->expected_waiting_time) -= burst;
    *(execution_inputs->waiting_time) += wait_time;
    *(execution_inputs->waiting_time_total) = *(execution_inputs->waiting_time);
    *(execution_inputs->turn_around_time) += run_time + wait_time;
    *(execution_inputs->turn_around_time_total) = *(execution_inputs->turn_around_time);
    local_exit_cmd = *(execution_inputs->exit_cmd);
  }
  return 0;
}
