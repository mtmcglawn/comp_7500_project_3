#define _RUN_TEST_C
#include "RunTest.h"


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


int run_test(int nargs, char **args, int *exit_cmd,
    command_data_struct *command_data)
{
  *exit_cmd = 4;
  if (nargs != 7)
  {
    fprintf(stdout, "\nWrong number of arguments\n");
    return 1;
  }
  *(command_data->total_complete) = 0;
  *(command_data->waiting_time) = 0;
  *(command_data->cpu_time) = 0;
  int jobs;
  int priority_max;
  int min_time;
  int max_time;
  sscanf(args[3], "%u", &jobs);
  sscanf(args[4], "%u", &priority_max);
  sscanf(args[5], "%u", &min_time);
  sscanf(args[6], "%u", &max_time);
  if (*(command_data->count) != 0)
  {
    fprintf(stdout, "\nWaiting for other jobs to finish...\n");
    while (*(command_data->count) != 0)
    {
      //sit and wait
    }
  }
  for (int i=0; i < jobs; i++)
  {
    char arg1[50];
    char arg2[50];
    char arg3[50];
    char arg4[50];
    char *new_args[10];
    int new_nargs = 4;
    int priority = (rand() % priority_max + 1);
    int local_cpu_time = (rand() % (max_time - min_time + 1) + min_time);
    sprintf(arg1, "%s", "run");
    sprintf(arg2, "%s", "test_proc");
    sprintf(arg3, "%d", local_cpu_time);
    sprintf(arg4, "%d", priority_max);
    new_args[0] = arg1;
    new_args[1] = arg2;
    new_args[2] = arg3;
    new_args[3] = arg4;
    *(command_data->is_run) = 0;
    begin_run(new_nargs, new_args, exit_cmd, command_data);
    *(command_data->is_run) = 1;
  }
  *(command_data->is_scheduled) = 0;
  if (strcmp(args[2], "fcfs") == 0)
  {
    run_fcfs(0, NULL, exit_cmd, command_data);
  }
  else if (strcmp(args[2], "sjf") == 0)
  {
    run_sjf(0, NULL, exit_cmd, command_data);
  }
  else if (strcmp(args[2], "priority") == 0)
  {
    run_priority(0, NULL, exit_cmd, command_data);
  }
  else
  {
    return 1;
  }
  *(command_data->is_scheduled) = 1;
  while (*(command_data->count) != 0)
  {
    //sit and wait
  }
  float total_runs = *(command_data->total_complete);
  fprintf(stdout, "Total number of jobs submitted: %u\n", total_runs);
  float turn_around = *(command_data->turn_around_time) / total_runs;
  float cpu = *(command_data->cpu_time_total) / total_runs;
  float waiting = *(command_data->waiting_time_total) / total_runs;
  float throughput = 1 / cpu;
  fprintf(stdout, "Average turnaround time:      %.2f seconds\n", turn_around);
  fprintf(stdout, "Average CPU time:             %.2f seconds\n", cpu);
  fprintf(stdout, "Average waiting time:         %.2f seconds\n", waiting);
  fprintf(stdout, "Throughput                    %.3f No./second\n", throughput);
  return 0;
}
