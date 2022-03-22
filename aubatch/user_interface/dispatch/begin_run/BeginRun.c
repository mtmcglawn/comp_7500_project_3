#define _BEGIN_RUN_C
#include "BeginRun.h"


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


int begin_run(int nargs, char **args, int *exit_cmd,
    command_data_struct *command_data)
{
  *exit_cmd = 2;
  time_t rtime = time(NULL);
  if (nargs != 4)
  {
    fprintf(stdout, "Incorrect number of arguments");
    return 1;
  }
  char *name;
  sscanf(args[1], "%s", command_data->jobBuffer[*(command_data->buf_head)].name);
  sprintf(name, "%s", command_data->jobBuffer[*(command_data->buf_head)].name);
  sscanf(args[3], "%d", &(command_data->jobBuffer[*(command_data->buf_head)].priority));
  sscanf(args[2], "%d", &(command_data->jobBuffer[*(command_data->buf_head)].burst));
  int burst = command_data->jobBuffer[*(command_data->buf_head)].burst;
  *(command_data->expected_waiting_time) += burst;
  command_data->jobBuffer[*(command_data->buf_head)].arrival = rtime;
  *(command_data->count) += 1;
  *(command_data->buf_head) += 1;
  command_data->jobBuffer[*(command_data->buf_head)].position = *(command_data->buf_head);
  pthread_cond_signal(command_data->process_buffer_full);
  char *policy_set;
  if (*(command_data->policy) == 0)
  {
    run_fcfs(0, NULL, exit_cmd, command_data);
    policy_set = "FCFS.";
  }
  else if (*(command_data->policy) == 1)
  {
    run_sjf(0, NULL, exit_cmd, command_data);
    policy_set = "SJF.";
  }
  else if (*(command_data->policy) == 2)
  {
    run_priority(0, NULL, exit_cmd, command_data);
    policy_set = "Priority.";
  }
  if (*(command_data->is_run))
  {
    fprintf(stdout, "Job %s", name);
    fprintf(stdout, " was submitted.\n");
    fprintf(stdout, "Total number of jobs in the queue: %u\n", *(command_data->count));
    fprintf(stdout, "Expected waiting time: %u seconds\n", *(command_data->expected_waiting_time));
    fprintf(stdout, "Scheduling Policy: %s\n", policy_set);

  }
  *(command_data->total)++;
  *(command_data->total_complete) = *(command_data->total);
  return 0;
}
