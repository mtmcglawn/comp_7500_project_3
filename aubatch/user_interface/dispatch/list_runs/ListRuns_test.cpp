#include <iostream>
#include "gtest/gtest.h"
extern "C" {
#include "ListRuns.h"
}

using namespace std;


TEST(ShowHelp, DoesAssertWork){
  ASSERT_TRUE(1 == 1);
}

TEST(ShowHelpTest, DoesNotCrash){
  testing::internal::CaptureStdout();
  command_data_struct *command_data = (
      command_data_struct *)malloc(
        sizeof(command_data_struct));
  int *exit_cmd = (int *)malloc(sizeof(int));
  char **help = (char **)malloc(sizeof(char*));
  char input[] = "help";
  u_int count = 0;
  command_data->count = &count;
  int policy = 0;
  command_data->policy = &policy;
  int buf_tail = 0;
  command_data->buf_tail = &buf_tail;
  job_def jobBuffer[MAX_PROCESS_COUNT - 1];
  command_data->jobBuffer = jobBuffer;
  *help = input;
  list_runs(1, help, exit_cmd, command_data);
  std::string output = testing::internal::GetCapturedStdout();
  ASSERT_TRUE(1 == 1);
}


int main(int argc, char **argv) {

  testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}
