#include <iostream>
#include "gtest/gtest.h"
extern "C" {
#include "RunFCFS.h"
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
  int policy = 1;
  command_data->policy = &policy;
  u_int count = 0;
  command_data->count = &count;
  int is_scheduled = 0;
  command_data->is_scheduled = &is_scheduled;
  int buf_tail = 0;
  command_data->buf_tail = &buf_tail;
  char **help = (char **)malloc(sizeof(char*));
  char input[] = "help";
  *help = input;
  run_fcfs(1, help, exit_cmd, command_data);
  std::string output = testing::internal::GetCapturedStdout();
  ASSERT_TRUE(1 == 1);
}


int main(int argc, char **argv) {

  testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}
