include_guard(GLOBAL)

#######################################
# Set up the Include Directories
#######################################
set(CMAKE_INC          ${CMAKE_DIR})
set(GET_INPUT_INC      ${GET_INPUT_DIR})
set(AU_BATCH_INC       ${AU_BATCH_DIR})
set(EXECUTION_INC      ${EXECUTION_DIR})
set(USER_INTERFACE_INC ${USER_INTERFACE_DIR})
set(THREAD_DATA_INC    ${THREAD_DATA_DIR})
set(DISPATCH_INC       ${DISPATCH_DIR})
set(COMMAND_DATA_INC   ${COMMAND_DATA_DIR})
set(SHOW_HELP_INC      ${SHOW_HELP_DIR})
set(QUIT_RUNS_INC      ${QUIT_RUNS_DIR})

set(COMMON_INCLUDES 
  ${CMAKE_INC}
	)
