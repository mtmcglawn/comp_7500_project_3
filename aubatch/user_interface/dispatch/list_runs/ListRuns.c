#define _LIST_RUNS_C
#include "ListRuns.h"


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


int list_runs(int nargs, char **args, int *exit_cmd,
    command_data_struct *command_data)
{
  *exit_cmd = 3;
  fprintf(stdout, "\nTotal Number of jobs in the qeueu: ");
  fprintf(stdout, "%u\n", *(command_data->count));
  fprintf(stdout, "Scheduling Policy: ");
  if (*(command_data->policy) == 0)
  {
    fprintf(stdout, "FCFS.\n");
  }
  else if (*(command_data->policy) == 1)
  {
    fprintf(stdout, "SJF.\n");
  }
  else if (*(command_data->policy) == 2)
  {
    fprintf(stdout, "Priority.\n");
  }
  fprintf(stdout, "Name    CPU_Time      Priority      Arrival_time    Progress\n");
  int i = *(command_data->buf_tail) - 1;
  struct tm *ptm;
  time_t time;
  int run = 1;
  int jobs = *(command_data->count) + 1;
  for (int j=0; j < jobs; j++)
  {
    if (i == MAX_PROCESS_COUNT)
    {
      i = 0;
    }
    fprintf(stdout, "%s\t", command_data->jobBuffer[i].name);
    fprintf(stdout, "%d\t\t", command_data->jobBuffer[i].burst);
    fprintf(stdout, "%d\t\t", command_data->jobBuffer[i].priority);
    time = command_data->jobBuffer[i].arrival;
    ptm = localtime(&time);
    fprintf(stdout, "%02d:%02d:%02d\t", ptm->tm_hour, ptm->tm_min, ptm->tm_sec);
    if (run)
    {
      fprintf(stdout, "RUN");
      run = 0;
    }
    fprintf(stdout, "\n");
    i++;
  }
  return 0;
}
