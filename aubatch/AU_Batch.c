#define _AU_BATCH_C
#include "AU_Batch.h"


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


int aubatch()
{
  char welcome_string[54] = "Welcome to Tyler's batch job scheduler Version 1.0\n";
  char second_line[56] = "Type 'help' to find out more about AUbatch commands.\n";
  strcat( welcome_string, second_line);
  fprintf(stdout, "%s", welcome_string);
  pthread_t user_interface_thread, execution_thread;
  int interface_err = pthread_create(&user_interface_thread, NULL, launch_user_interface, NULL);
  int execution_err = pthread_create(&execution_thread, NULL, launch_execution, NULL);
  if (interface_err != 0 || execution_err != 0)
  {
    fprintf(stdout, "Error creating threads");
    return 1;
  }
  return 0;
}
