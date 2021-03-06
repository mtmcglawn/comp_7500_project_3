#ifndef _BEGIN_RUN_H
#define _BEGIN_RUN_H


#include <pthread.h>
#include <stdio.h>
#include <time.h>


#include "CommandData.h"
#include "RunFCFS.h"
#include "RunSJF.h"
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


int begin_run(int nargs, char **args, int *exit_cmd,
    command_data_struct *command_data);


#endif
