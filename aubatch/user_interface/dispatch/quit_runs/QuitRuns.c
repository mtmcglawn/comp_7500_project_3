#define _QUIT_RUNS_C
#include "QuitRuns.h"


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


int quit_runs(int nargs, char **args, int **exit_cmd,
    command_data_struct *command_data)
{
  (void)nargs;
  (void)args;
  int ret_val = 0;
  *exit_cmd = &ret_val;
  float total_runs = command_data->total - *(command_data->count);
  if (total_runs < 1) {
    fprintf(stdout, "Cannot show statistics as not enough processes have finished\n");
    return 0;
  }
  fprintf(stdout, "Total number of jobs submitted: %u\n", command_data->total);
  float turn_around = command_data->turn_around_time / total_runs;
  float cpu = command_data->cpu_time / total_runs;
  float wait_time = command_data->waiting_time / total_runs;
  float throughput = 1 / cpu;
  fprintf(stdout, "Average turnaround time:    %.2f seconds\n", command_data->total);
  fprintf(stdout, "Average CPU time:           %.2f seconds\n", cpu);
  fprintf(stdout, "Average waiting time:       %.2f seconds\n", wait_time);
  fprintf(stdout, "Throughput                  %.3f No./second\n", throughput);
  return 0;
}
