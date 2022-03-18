#include <iostream>
#include "gtest/gtest.h"
extern "C" {
#include "ThreadData.h"
}

using namespace std;


TEST(PWordCount, DoesAssertWork){
  ASSERT_TRUE(1 == 1);
}

TEST(ShowHelpTest, DoesNotCrash){
  thread_data_struct *data = (
      thread_data_struct *)malloc(
        sizeof(thread_data_struct));
  testing::internal::CaptureStdout();
  get_thread_data(data);
  std::string output = testing::internal::GetCapturedStdout();
  ASSERT_TRUE(1 == 1);
}


int main(int argc, char **argv) {

  testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}
