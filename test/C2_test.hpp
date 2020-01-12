#include "../C2/2-3/htoi.h"
#include "gtest/gtest.h"

TEST(SAMPLE, sample1){
    char s[] = "0xff";
    EXPECT_EQ(htoi(s), 255);
}