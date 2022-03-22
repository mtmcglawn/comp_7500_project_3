#define _COMMAND_DATA_C
#include "CommandData.h"


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


int get_command_data(command_data_struct *command_data)
{
  int init_policy = 0;
  u_int total = 0;
  u_int total_complete = 0;
  int is_run = 1;
  int is_scheduled = 1;
  command_data->policy = &init_policy;
  command_data->total = &total;
  command_data->total_complete = &total_complete;
  command_data->count = malloc(sizeof(u_int));
  command_data->is_run = &is_run;
  command_data->is_scheduled = &is_scheduled;
  return 0;
}
