#define _RUN_PRIORITY_C
#include "RunPriority.h"


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


int run_priority(int nargs, char **args, int *exit_cmd,
    command_data_struct *command_data)
{
  if (*(command_data->policy) == 2) {
    return 0;
  }
  *(command_data->policy) = 2;
  int local_buf_tail = *(command_data->buf_tail);
  for (int i=0; i < *(command_data->count); i++)
  {
    if (local_buf_tail == MAX_PROCESS_COUNT)
    {
      local_buf_tail = 0;
    }
    int tmp_buf_tail = local_buf_tail;
    int min_buf_tail = local_buf_tail;
    int limit = *(command_data->count) - i;
    long int min_priority = command_data->jobBuffer[tmp_buf_tail].priority;
    for (int j = i; j < limit; j++)
    {
      int tmp = command_data->jobBuffer[tmp_buf_tail].priority;
      if (tmp < min_priority)
      {
        min_priority = tmp;
        min_buf_tail = tmp_buf_tail;
      }
      tmp_buf_tail++;
    }
    if (min_buf_tail != local_buf_tail)
    {
      job_def tmp_job;
      strcpy(tmp_job.name, command_data->jobBuffer[local_buf_tail].name);
      tmp_job.burst = command_data->jobBuffer[local_buf_tail].burst;
      tmp_job.priority = command_data->jobBuffer[local_buf_tail].priority;
      tmp_job.arrival = command_data->jobBuffer[local_buf_tail].arrival;
      strcpy(command_data->jobBuffer[local_buf_tail].name, command_data->jobBuffer[min_buf_tail].name);
      command_data->jobBuffer[local_buf_tail].burst, command_data->jobBuffer[min_buf_tail].burst;
      command_data->jobBuffer[local_buf_tail].priority, command_data->jobBuffer[min_buf_tail].priority;
      command_data->jobBuffer[local_buf_tail].arrival, command_data->jobBuffer[min_buf_tail].arrival;
      strcpy(command_data->jobBuffer[min_buf_tail].name, tmp_job.name);
      command_data->jobBuffer[min_buf_tail].burst, tmp_job.burst;
      command_data->jobBuffer[min_buf_tail].priority, tmp_job.priority;
      command_data->jobBuffer[min_buf_tail].arrival, tmp_job.arrival;
    }
    local_buf_tail++;
  }
  if (*(command_data->is_scheduled))
  {
    fprintf(stdout, "Scheduling policy is switched to FCFS. All the %u waiting jobs\nhave been rescheduled.", *(command_data->count));
  }
  return 0;
}
