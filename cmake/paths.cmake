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
