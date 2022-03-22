include_guard(GLOBAL)

#######################################
# Set up the directory locations
#######################################
set(TOP_LEVEL_DIR      ${BASE_DIR})


set(BUILD_DIR          ${CMAKE_SOURCE_DIR}/build)

set(CMAKE_DIR          ${TOP_LEVEL_DIR}/cmake)
set(EXTERNAL_DEPS_DIR  ${TOP_LEVEL_DIR}/external)
set(AU_BATCH_DIR       ${TOP_LEVEL_DIR}/aubatch)

set(GOOGLETEST_DIR     ${EXTERNAL_DEPS_DIR}/googletest)

set(EXECUTION_DIR      ${AU_BATCH_DIR}/execution)
set(USER_INTERFACE_DIR ${AU_BATCH_DIR}/user_interface)
set(GET_INPUT_DIR      ${AU_BATCH_DIR}/get_input)
set(THREAD_DATA_DIR    ${AU_BATCH_DIR}/thread_data)

set(DISPATCH_DIR       ${USER_INTERFACE_DIR}/dispatch)
set(COMMAND_DATA_DIR   ${USER_INTERFACE_DIR}/command_data)

set(SHOW_HELP_DIR      ${DISPATCH_DIR}/show_help)
set(QUIT_RUNS_DIR      ${DISPATCH_DIR}/quit_runs)
set(BEGIN_RUN_DIR      ${DISPATCH_DIR}/begin_run)
set(LIST_RUNS_DIR      ${DISPATCH_DIR}/list_runs)
set(RUN_TEST_DIR       ${DISPATCH_DIR}/run_test)

set(RUN_FCFS_DIR       ${BEGIN_RUN_DIR}/run_fcfs)
set(RUN_SJF_DIR        ${BEGIN_RUN_DIR}/run_sjf)
set(RUN_PRIORITY_DIR   ${BEGIN_RUN_DIR}/run_priority)
