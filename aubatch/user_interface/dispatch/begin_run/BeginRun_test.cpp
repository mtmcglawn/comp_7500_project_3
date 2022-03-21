#include <iostream>
#include "gtest/gtest.h"
extern "C" {
#include "BeginRun.h"
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
  *help = input;
  begin_run(1, help, exit_cmd, command_data);
  std::string output = testing::internal::GetCapturedStdout();
  ASSERT_TRUE(1 == 1);
}


int main(int argc, char **argv) {

  testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}
