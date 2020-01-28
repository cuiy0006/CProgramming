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
    escape(s, t1);
    escape_reverse(t1, t2);
    EXPECT_STREQ("abc\\nd e\\tfgh", t1);
    EXPECT_STREQ(s, t2);
}

TEST(C3, Q3){
    char s1_0[] = "a-b-c";
    char s2_0[1024];
    expand(s1_0, s2_0);
    EXPECT_STREQ("abc", s2_0);

    char s1_1[] = "a-z0-9";
    char s2_1[1024];
    expand(s1_1, s2_1);
    EXPECT_STREQ("abcdefghijklmnopqrstuvwxyz0123456789", s2_1);

    char s1_2[] = "---a-z----";
    char s2_2[1024];
    expand(s1_2, s2_2);
    EXPECT_STREQ("---abcdefghijklmnopqrstuvwxyz----", s2_2);

    char s1_3[] = "--a-d0-3E-G--";
    char s2_3[1024];
    expand(s1_3, s2_3);
    EXPECT_STREQ("--abcd0123EFG--", s2_3);
}

TEST(C3, Q4){
    int n0 = INT_MIN;
    char s0[1024];
    itoa(n0, s0);
    EXPECT_STREQ("-2147483648", s0);

    int n1 = INT_MAX;
    char s1[1024];
    itoa(n1, s1);
    EXPECT_STREQ("2147483647", s1);

    int n2 = 0;
    char s2[1024];
    itoa(n2, s2);
    EXPECT_STREQ("0", s2);
}

TEST(C3, Q5){
    int n0 = INT_MIN;
    char s0_2[1024];
    char s0_8[1024];
    char s0_16[1024];
    itob(n0, s0_2, 2);
    itob(n0, s0_8, 8);
    itob(n0, s0_16, 16);
    EXPECT_STREQ("-10000000000000000000000000000000", s0_2);
    EXPECT_STREQ("-20000000000", s0_8);
    EXPECT_STREQ("-80000000", s0_16);

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
    EXPECT_STREQ("1001001100101100000001011010010", s1_2);
    EXPECT_STREQ("11145401322", s1_8);
    EXPECT_STREQ("499602d2", s1_16);
}

TEST(C3, Q6){
    int n0 = INT_MIN;
    char s0[1024];
    itoa_width(n0, s0, 15);
    EXPECT_STREQ("    -2147483648", s0);

    int n1 = INT_MAX;
    char s1[1024];
    itoa_width(n1, s1, 15);
    EXPECT_STREQ("     2147483647", s1);

    int n2 = 0;
    char s2[1024];
    itoa_width(n2, s2, 2);
    EXPECT_STREQ(" 0", s2);

    int n3 = -1024;
    char s3[1024];
    itoa_width(n3, s3, 5);
    EXPECT_STREQ("-1024", s3);
}