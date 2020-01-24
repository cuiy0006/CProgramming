#include "gtest/gtest.h"
#include <string.h>
#include <limits.h>
#include "../util/util.h"
#include "../C3/3-1/binsearch.h"
#include "../C3/3-2/escape.h"
#include "../C3/3-3/expand.h"
#include "../C3/3-4/itoa.h"
#include "../C3/3-5/itob.h"
#include "../C3/3-6/itoa_width.h"

TEST(C3, Q1){
    int v1[] = {1, 2, 3, 4, 5, 6, 7};
    EXPECT_EQ(3, binsearch(4, v1, 7));
    EXPECT_EQ(0, binsearch(1, v1, 7));
    EXPECT_EQ(6, binsearch(7, v1, 7));
    EXPECT_EQ(-1, binsearch(8, v1, 7));
    EXPECT_EQ(-1, binsearch(0, v1, 7));

    int v2[] = {2, 2, 2, 2, 2, 2, 2};
    EXPECT_EQ(0, binsearch(2, v2, 7));
    EXPECT_EQ(-1, binsearch(3, v2, 7));
    EXPECT_EQ(-1, binsearch(4, v2, 7));

    int v3[] = {2, 3, 3, 3, 3, 6, 7};
    EXPECT_EQ(1, binsearch(3, v3, 7));
}

TEST(C3, Q2){
    char s[] = "abc\nd e\tfgh";
    char t1[20];
    char t2[20];
    char expect1[] = "abc\\nd e\\tfgh";
    escape(s, t1);
    escape_reverse(t1, t2);
    EXPECT_EQ(0, strcmp(t1, expect1));
    EXPECT_EQ(0, strcmp(t2, s));
}

TEST(C3, Q3){
    char s1_0[] = "a-b-c";
    char s2_0[1024];
    char expect_0[] = "abc";
    expand(s1_0, s2_0);
    EXPECT_EQ(0, strcmp(s2_0, expect_0));

    char s1_1[] = "a-z0-9";
    char s2_1[1024];
    char expect_1[] = "abcdefghijklmnopqrstuvwxyz0123456789";
    expand(s1_1, s2_1);
    EXPECT_EQ(0, strcmp(s2_1, expect_1));

    char s1_2[] = "---a-z----";
    char s2_2[1024];
    char expect_2[] = "---abcdefghijklmnopqrstuvwxyz----";
    expand(s1_2, s2_2);
    EXPECT_EQ(0, strcmp(s2_2, expect_2));

    char s1_3[] = "--a-d0-3E-G--";
    char s2_3[1024];
    char expect_3[] = "--abcd0123EFG--";
    expand(s1_3, s2_3);
    EXPECT_EQ(0, strcmp(s2_3, expect_3));
}

TEST(C3, Q4){
    int n0 = INT_MIN;
    char s0[1024];
    char expect0[] = "-2147483648";
    itoa(n0, s0);
    EXPECT_EQ(0, strcmp(s0, expect0));

    int n1 = INT_MAX;
    char s1[1024];
    char expect1[] = "2147483647";
    itoa(n1, s1);
    EXPECT_EQ(0, strcmp(s1, expect1));

    int n2 = 0;
    char s2[1024];
    char expect2[] = "0";
    itoa(n2, s2);
    EXPECT_EQ(0, strcmp(s2, expect2));
}

TEST(C3, Q5){
    int n0 = INT_MIN;
    char s0_2[1024];
    char s0_8[1024];
    char s0_16[1024];
    char expect0_2[] = "-10000000000000000000000000000000";
    char expect0_8[] = "-20000000000";
    char expect0_16[] = "-80000000";
    itob(n0, s0_2, 2);
    itob(n0, s0_8, 8);
    itob(n0, s0_16, 16);
    EXPECT_EQ(0, strcmp(s0_2, expect0_2));
    EXPECT_EQ(0, strcmp(s0_8, expect0_8));
    EXPECT_EQ(0, strcmp(s0_16, expect0_16));

    int n1 = 1234567890;
    char s1_2[1024];
    char s1_8[1024];
    char s1_16[1024];
    char expect1_2[] = "1001001100101100000001011010010";
    char expect1_8[] = "11145401322";
    char expect1_16[] = "499602d2";

    itob(n1, s1_2, 2);
    itob(n1, s1_8, 8);
    itob(n1, s1_16, 16);
    EXPECT_EQ(0, strcmp(s1_2, expect1_2));
    EXPECT_EQ(0, strcmp(s1_8, expect1_8));
    EXPECT_EQ(0, strcmp(s1_16, expect1_16));
}

TEST(C3, Q6){
    int n0 = INT_MIN;
    char s0[1024];
    char expect0[] = "    -2147483648";
    itoa_width(n0, s0, 15);
    EXPECT_EQ(0, strcmp(s0, expect0));

    int n1 = INT_MAX;
    char s1[1024];
    char expect1[] = "     2147483647";
    itoa_width(n1, s1, 15);
    EXPECT_EQ(0, strcmp(s1, expect1));

    int n2 = 0;
    char s2[1024];
    char expect2[] = " 0";
    itoa_width(n2, s2, 2);
    EXPECT_EQ(0, strcmp(s2, expect2));

    int n3 = -1024;
    char s3[1024];
    char expect3[] = "-1024";
    itoa_width(n3, s3, 5);
    EXPECT_EQ(0, strcmp(s3, expect3));
}