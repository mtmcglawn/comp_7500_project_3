#include <iostream>
#include "gtest/gtest.h"
extern "C" {
#include "Execution.h"
}

using namespace std;


TEST(Execution, DoesAssertWork){
  ASSERT_TRUE(1 == 1);
}


int main(int argc, char **argv) {

  testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}
