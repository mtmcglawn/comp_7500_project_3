#include <iostream>
#include "gtest/gtest.h"
extern "C" {
#include "Dispatch.h"
}

using namespace std;


TEST(Dispatch, DoesAssertWork){
  ASSERT_TRUE(1 == 1);
}

struct DispatchTest : public testing::Test {
  int *exit_cmd = (int *)malloc(sizeof(int));
  int *err_rcvd = (int *)malloc(sizeof(int));
  char *input = (char *)malloc(INPUT_BUFFER_MAX_SIZE * sizeof(char));
  command_data_struct *command_data = (
      command_data_struct *)malloc(
        sizeof(command_data_struct));

  void SetUp() {
    *exit_cmd = -1;
    *err_rcvd = 0;
    char quit[] = "quit";
    input = quit;
  }
  void TearDown() {}
};

TEST_F(DispatchTest, DoesNotCrash){
  testing::internal::CaptureStdout();
  dispatch(input, exit_cmd, &err_rcvd, command_data);
  std::string output = testing::internal::GetCapturedStdout();
  ASSERT_TRUE(1 == 1);
}

/*
struct AUBatchTest : public testing::Test {
  string expected_output = "Welcome to Tyler's batch job scheduler Version 1.0\nType 'help' to find out more about AUbatch commands.\n";
  void SetUp() {}
  void TearDown() {}
};

TEST_F(AUBatchTest, AUBatchReturnsInt){
  testing::internal::CaptureStdout();
  ASSERT_EQ(typeid(aubatch()), typeid(int));
  std::string output = testing::internal::GetCapturedStdout();
}

TEST_F(AUBatchTest, AUBatchOutputCorrect){
  testing::internal::CaptureStdout();
  aubatch();
  std::string output = testing::internal::GetCapturedStdout();
  ASSERT_EQ(output, expected_output);
}
*/


int main(int argc, char **argv) {

  testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}
