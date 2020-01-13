#include "../C2/2-3/htoi.h"
#include "../C2/2-4/squeeze.h"
#include "../C2/2-5/any.h"
#include "gtest/gtest.h"
#include <string.h>
#include <iostream>

TEST(C2, Q3){
    char s0[] = "ff";
    char s1[] = "0xff";
    char s2[] = "0Xff";
    char s3[] = "0xfF";
    char s4[] = "0x10";
    EXPECT_EQ(255, htoi(s0));
    EXPECT_EQ(255, htoi(s1));
    EXPECT_EQ(255, htoi(s2));
    EXPECT_EQ(255, htoi(s3));
    EXPECT_EQ(16, htoi(s4));
}

TEST(C2, Q4){
    char s10[] = "123456789";
    char s20[] = "13579";
    squeeze(s10, s20);
    EXPECT_EQ(0, strcmp(s10, "2468"));

    char s11[] = "123456789";
    char s21[] = "1199";
    squeeze(s11, s21);
    EXPECT_EQ(0, strcmp(s11, "2345678"));

    char s12[] = "";
    char s22[] = "1199";
    squeeze(s12, s22);
    EXPECT_EQ(0, strcmp(s12, ""));

    char s13[] = "123456789";
    char s23[] = "";
    squeeze(s13, s23);
    EXPECT_EQ(0, strcmp(s13, "123456789"));

    char s14[] = "11335577";
    char s24[] = "15";
    squeeze(s14, s24);
    EXPECT_EQ(0, strcmp(s14, "3377"));
}

TEST(C2, Q5){
    char s10[] = "123456789";
    char s20[] = "987654";
    EXPECT_EQ(3, any(s10, s20));

    char s11[] = "123456789";
    char s21[] = "abcdefg@!#$";
    EXPECT_EQ(-1, any(s11, s21));

    char s12[] = "125456789";
    char s22[] = "555";
    EXPECT_EQ(2, any(s12, s22));
}