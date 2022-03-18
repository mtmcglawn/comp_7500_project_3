#include <iostream>
#include "gtest/gtest.h"
extern "C" {
#include "CommandData.h"
}

using namespace std;


TEST(PWordCount, DoesAssertWork){
  ASSERT_TRUE(1 == 1);
}

TEST(ShowHelpTest, DoesNotCrash){
  command_data_struct *data = (
      command_data_struct *)malloc(
        sizeof(command_data_struct));
  testing::internal::CaptureStdout();
  get_command_data(data);
  std::string output = testing::internal::GetCapturedStdout();
  ASSERT_TRUE(1 == 1);
}


int main(int argc, char **argv) {

  testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}
