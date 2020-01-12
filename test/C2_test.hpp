#include "../C2/2-3/htoi.h"
#include "gtest/gtest.h"

TEST(C2, Q3){
    char s0[] = "ff";
    char s1[] = "0xff";
    char s2[] = "0Xff";
    char s3[] = "0xfF";
    char s4[] = "0x10";
    EXPECT_EQ(htoi(s0), 255);
    EXPECT_EQ(htoi(s1), 255);
    EXPECT_EQ(htoi(s2), 255);
    EXPECT_EQ(htoi(s3), 255);
    EXPECT_EQ(htoi(s4), 16);
}