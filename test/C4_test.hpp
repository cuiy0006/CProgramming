#include "gtest/gtest.h"
#include <string.h>
#include "../C4/4-1/strrindex.h"
#include "../C4/4-2/atof.h"
#include "../C4/4-12/itoa_recursive.h"
#include "../C4/4-13/reverse_recursive.h"

TEST(C4, Q1){
    char s0[] = "123abc123abc123";
    char t0[] = "abc";
    EXPECT_EQ(9, strrindex(s0, t0));

    char s1[] = "123 abc";
    char t1[] = "abc";
    EXPECT_EQ(4, strrindex(s1, t1));

    char s2[] = "123 abc";
    char t2[] = "";
    EXPECT_EQ(-1, strrindex(s2, t2));

    char s3[] = "123 bca abd acd";
    char t3[] = "abc";
    EXPECT_EQ(-1, strrindex(s3, t3));

    char s4[] = "";
    char t4[] = "abc";
    EXPECT_EQ(-1, strrindex(s4, t4));
}

TEST(C4, Q2){
    char s0[] = "-123.45";
    EXPECT_EQ(-123.45, atof(s0));

    char s1[] = "12345";
    EXPECT_EQ(12345, atof(s1));

    char s2[] = "+0";
    EXPECT_EQ(0, atof(s2));

    char s3[] = "-123.45e-6";
    EXPECT_EQ(-0.00012345, atof(s3));

    char s4[] = "-123.45e6";
    EXPECT_EQ(-123450000, atof(s4));

    char s5[] = "-123.45e+6";
    EXPECT_EQ(-123450000, atof(s5));

    char s6[] = "-123.45e-0";
    EXPECT_EQ(-123.45, atof(s6));
}

TEST(C4, Q12){
    int n0 = INT_MIN;
    char s0[1024];
    itoa_recursive(n0, s0);
    EXPECT_STREQ("-2147483648", s0);

    int n1 = INT_MAX;
    char s1[1024];
    itoa_recursive(n1, s1);
    EXPECT_STREQ("2147483647", s1);

    int n2 = 0;
    char s2[1024];
    itoa_recursive(n2, s2);
    EXPECT_STREQ("0", s2);
}

TEST(C4, Q13){
    char s0[] = "12345";
    reverse_recursive(s0);
    EXPECT_STREQ("54321", s0);

    char s1[] = "";
    reverse_recursive(s1);
    EXPECT_STREQ("", s1);

    char s2[] = "1234";
    reverse_recursive(s2);
    EXPECT_STREQ("4321", s2);
}