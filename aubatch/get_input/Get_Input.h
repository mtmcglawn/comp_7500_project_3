#ifndef _GET_INPUT_H
#define _GET_INPUT_H


#include <stdio.h>
#include <stdlib.h>


#include "Config.h"


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


void get_input(char **input, size_t *input_size);

void get_user_interface_input(char **input, size_t *input_size);


#endif
