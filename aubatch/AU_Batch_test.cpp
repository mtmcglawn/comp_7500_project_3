#include <iostream>
#include "gtest/gtest.h"
extern "C" {
#include "AU_Batch.h"
}

using namespace std;


TEST(PWordCount, DoesAssertWork){
  ASSERT_TRUE(1 == 1);
}

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


int main(int argc, char **argv) {

  testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}
