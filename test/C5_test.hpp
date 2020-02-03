#include "gtest/gtest.h"
#include "../C5/5-3/strcat_p.h"
#include "../C5/5-4/strend.h"
#include "../C5/5-5/str_op.h"

TEST(C5, Q3){
    char s0[] = "1234";
    char t0[] = "5678";
    strcat_p(s0, t0);
    EXPECT_STREQ("12345678", s0);

    char s1[] = "";
    char t1[] = "1234";
    strcat_p(s1, t1);
    EXPECT_STREQ("1234", s1);

    char s2[] = "1234";
    char t2[] = "";
    strcat_p(s2, t2);
    EXPECT_STREQ("1234", s2);
}

TEST(C5, Q4){
    char s0[] = "1234567";
    char t0[] = "567";
    EXPECT_EQ(1, strend(s0, t0));

    char s1[] = "567";
    char t1[] = "567";
    EXPECT_EQ(1, strend(s1, t1));

    char s2[] = "567";
    char t2[] = "1234567";
    EXPECT_EQ(0, strend(s2, t2));

    char s3[] = "1234";
    char t3[] = "567";
    EXPECT_EQ(0, strend(s3, t3));
}

TEST(C5, Q5){
    char src0[] = "123456";
    char dest0[7];
    strncpy_p(dest0, src0, 6);
    EXPECT_STREQ("123456", dest0);

    char src1[] = "123456";
    char dest1[7];
    strncpy_p(dest1, src1, 3);
    EXPECT_STREQ("123", dest1);

    char src2[] = "123456";
    char dest2[7];
    strncpy_p(dest2, src2, 10);
    EXPECT_STREQ("123456", dest2);

    char src3[] = "123456";
    char dest3[] = "";
    strncat_p(dest3, src3, 6);
    EXPECT_STREQ("123456", dest3);

    char src4[] = "123456";
    char dest4[] = "1234";
    strncat_p(dest4, src4, 6);
    EXPECT_STREQ("1234123456", dest4);

    char src5[] = "";
    char dest5[] = "1234";
    strncat_p(dest5, src5, 6);
    EXPECT_STREQ("1234", dest5);

    char src6[] = "123456";
    char dest6[] = "1234";
    strncat_p(dest6, src6, 3);
    EXPECT_STREQ("1234123", dest6);

    char str0[] = "12345";
    char str1[] = "12345";
    EXPECT_EQ(0, strncmp_p(str0, str1, 5));
    
    char str2[] = "12345";
    char str3[] = "12345";
    EXPECT_EQ(0, strncmp_p(str2, str3, 8));

    char str4[] = "12378";
    char str5[] = "12345";
    EXPECT_EQ(0, strncmp_p(str4, str5, 3));

    char str6[] = "12345";
    char str7[] = "12";
    EXPECT_NE(0, strncmp_p(str6, str7, 3));
}