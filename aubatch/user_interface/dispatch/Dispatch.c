#define _DISPATCH_C
#include "Dispatch.h"


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


static struct {
  const char *command;
  int (*func)(int nargs, char **args, int *exit_cmd,
      command_data_struct *command_data);
} cmdmapping[] =
{
  {"?\n",        show_help},
  {"h\n",        show_help},
  {"help\n",     show_help},
  {"r",          begin_run},
  {"run",        begin_run},
  {"q\n",        quit_runs},
  {"quit\n",     quit_runs},
  {"l\n",        list_runs},
  {"list\n",     list_runs},
  {"sjf\n",      run_sjf},
  {"fcfs\n",     run_fcfs},
  {"priority\n", run_priority},
  {"test",       run_test},
  {"test\n",     run_test},
  {"t",          run_test},
  {NULL,         NULL}
};


int dispatch(char *input, int *exit_cmd, int **err_rcvd,
    command_data_struct *command_data)
{
  char *args[MAX_ARG_NUMBER];
  int arg_count = 0;
  char *context = NULL;
  for (char *command=strtok_r(input, " ", &context); command != NULL; command=strtok_r(NULL, " ", &context))
  {
    if (arg_count >= MAX_ARG_NUMBER - 1)
    {
      fprintf(stdout, "Too many arguments");
      *exit_cmd = 0;
      return 1;
    }
    args[arg_count++] = command;
  }
  if (arg_count == 0)
  {
    *exit_cmd = 0;
    return 2;
  }
  for (int i=0; cmdmapping[i].command; i++)
  {
    if (*cmdmapping[i].command && !strcmp(args[0], cmdmapping[i].command))
    {
      assert(cmdmapping[i].func != NULL);
      return cmdmapping[i].func(arg_count, args, exit_cmd, command_data);
    }
  }
  fprintf(stdout, "Command '%s' not found", args[0]);
  return 3;
}
