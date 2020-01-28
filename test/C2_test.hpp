#include "../C2/2-3/htoi.h"
#include "../C2/2-4/squeeze.h"
#include "../C2/2-5/any.h"
#include "../C2/2-6/setbits.h"
#include "../C2/2-7/invert.h"
#include "../C2/2-8/rightrot.h"
#include "../C2/2-9/bitcount.h"
#include "../C2/2-10/lower.h"
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
    EXPECT_STREQ("2468", s10);

    char s11[] = "123456789";
    char s21[] = "1199";
    squeeze(s11, s21);
    EXPECT_STREQ("2345678", s11);

    char s12[] = "";
    char s22[] = "1199";
    squeeze(s12, s22);
    EXPECT_STREQ("", s12);

    char s13[] = "123456789";
    char s23[] = "";
    squeeze(s13, s23);
    EXPECT_STREQ("123456789", s13);

    char s14[] = "11335577";
    char s24[] = "15";
    squeeze(s14, s24);
    EXPECT_STREQ("3377", s14);
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

TEST(C2, Q6){
    unsigned x0 = 0b111111111;
    unsigned y0 = 0b000000000;
    EXPECT_EQ(0b110000111, setbits(x0, 3, 4, y0));

    unsigned x1 = 0b111111111;
    unsigned y1 = 0b000000000;
    EXPECT_EQ(0b111111111, setbits(x1, 3, 0, y1));

    unsigned x2 = 0b111111111;
    unsigned y2 = 0b000000000;
    EXPECT_EQ(0b111111000, setbits(x2, 0, 3, y2));
}

TEST(C2, Q7){
    unsigned x0 = 0b111111111;
    EXPECT_EQ(0b110000111, invert(x0, 3, 4));

    unsigned x1 = 0b101010101;
    EXPECT_EQ(0b100101101, invert(x1, 3, 4));
}

TEST(C2, Q8){
    unsigned x0 = 0x1234ABCD;
    EXPECT_EQ(0x1234ABCD, rightrot(x0, 0));
    EXPECT_EQ(0xD1234ABC, rightrot(x0, 4));
    EXPECT_EQ(0xCD1234AB, rightrot(x0, 8));
    EXPECT_EQ(0xCD1234AB, rightrot(x0, 40));
}

TEST(C2, Q9){
    EXPECT_EQ(bitcount_old(1234), bitcount(1234));
    EXPECT_EQ(bitcount_old(4321), bitcount(4321));
    EXPECT_EQ(bitcount_old(0), bitcount(0));
    EXPECT_EQ(bitcount_old(0xFFFFFFFF), bitcount(0xFFFFFFFF));
}

TEST(C2, Q10){
    EXPECT_EQ('a', lower('A'));
    EXPECT_EQ('a', lower('a'));
    EXPECT_EQ('z', lower('Z'));
    EXPECT_EQ('1', lower('1'));
}