#include <iostream>
#include "gtest/gtest.h"
extern "C" {
#include "UserInterface.h"
}

using namespace std;


TEST(UserInterface, DoesAssertWork){
  ASSERT_TRUE(1 == 1);
}

struct UserInterfaceTest : public testing::Test {
  pthread_mutex_t ui_queue_lock;
  int process_count_in_queue = 0;
  pthread_cond_t process_buffer_empty;

  struct user_interface_inputs_struct *user_interface_inputs = (
      struct user_interface_inputs_struct *)malloc(
        sizeof(struct user_interface_inputs_struct));
  void SetUp() {
    user_interface_inputs->ui_queue_lock = ui_queue_lock;
    user_interface_inputs->process_count_in_queue = &process_count_in_queue;
    user_interface_inputs->process_buffer_empty = process_buffer_empty;
  }
  void TearDown() {}
};

TEST_F(UserInterfaceTest, DoesNotCrash){
  testing::internal::CaptureStdout();
  run_user_interface(user_interface_inputs);
  std::string output = testing::internal::GetCapturedStdout();
  ASSERT_TRUE(1 == 1);
}

TEST_F(UserInterfaceTest, CorrectOutput){
  testing::internal::CaptureStdout();
  run_user_interface(user_interface_inputs);
  std::string output = testing::internal::GetCapturedStdout();
  ASSERT_EQ(output, "\n>");
}
/*
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
