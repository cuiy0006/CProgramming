#include "gtest/gtest.h"
#include "C2_test.hpp"
#include "C3_test.hpp"
#include "C4_test.hpp"
#include "C5_test.hpp"
#include "C6_test.hpp"
#include "C7_test.hpp"
#include "C8_test.hpp"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}