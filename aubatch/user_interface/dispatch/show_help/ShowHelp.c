#define _SHOW_HELP_C
#include "ShowHelp.h"


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


int show_help(int nargs, char **args, int *exit_cmd,
    command_data_struct *command_data)
{
  (void)nargs;
  (void)args;
  fprintf(stdout, "run <job> <time> <priority>: submit a job named <job>,\n");
  fprintf(stdout, "                             execution time is <time>,\n");
  fprintf(stdout, "                             priority is <priority>.\n");
  fprintf(stdout, "list: display the job status.\n");
  fprintf(stdout, "fcfs: change the scheduling policy to FCFS.\n");
  fprintf(stdout, "sjf: change the scheduling policy to SJF.\n");
  fprintf(stdout, "priority: change the scheduling policy to priority.\n");
  fprintf(stdout, "test: <benchmark> <policy> <num_of_jobs> <priority_levels>\n");
  fprintf(stdout, "      <main_CPU_time> <max_CPU_time>\n");
  fprintf(stdout, "quit: exit AUbatch\n");
  fprintf(stdout, "help: print this menu\n");
  *exit_cmd = 1;
  return 0;
}
