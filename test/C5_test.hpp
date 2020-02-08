#include "gtest/gtest.h"
#include "../C5/5-3/strcat_p.h"
#include "../C5/5-4/strend.h"
#include "../C5/5-5/str_op.h"
#include "../C5/5-6/atoi_p.h"
#include "../C5/5-6/itoa_p.h"
#include "../C5/5-6/reverse_p.h"
#include "../C5/5-6/itob_p.h"
#include "../C5/5-6/itoa_width_p.h"
#include "../C5/5-6/strindex_p.h"
#include "../C5/5-8/year_month_day_conversion.h"


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

TEST(C5, Q5_strncpy_p){
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
}

TEST(C5, Q5_strncat_p){
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
}

TEST(C5, Q5_strncmp_p){
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

TEST(C5, Q6_atoi_p){
    char s0[] = "10086";
    EXPECT_EQ(10086, atoi_p(s0));

    char s1[] = "-10086";
    EXPECT_EQ(-10086, atoi_p(s1));

    char s2[] = "+10086";
    EXPECT_EQ(10086, atoi_p(s2));

    char s3[] = "   -10086   ";
    EXPECT_EQ(-10086, atoi_p(s3));
}

TEST(C5, Q6_itoa_p){
    char s0[100];
    itoa_p(10086, s0);
    EXPECT_STREQ("10086", s0);

    char s1[100];
    itoa_p(-10086, s1);
    EXPECT_STREQ("-10086", s1);

    char s2[100];
    itoa_p(0, s2);
    EXPECT_STREQ("0", s2);
}

TEST(C5, Q6_reverse_p){
    char s0[] = "12345";
    reverse_p(s0);
    EXPECT_STREQ("54321", s0);

    char s1[] = "";
    reverse_p(s1);
    EXPECT_STREQ("", s1);

    char s2[] = "54321-";
    reverse_p(s2);
    EXPECT_STREQ("-12345", s2);
}

TEST(C5, Q6_itob_p){
    int n0 = INT_MIN;
    char s0_2[1024];
    char s0_8[1024];
    char s0_16[1024];
    itob_p(n0, s0_2, 2);
    itob_p(n0, s0_8, 8);
    itob_p(n0, s0_16, 16);
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

    itob_p(n1, s1_2, 2);
    itob_p(n1, s1_8, 8);
    itob_p(n1, s1_16, 16);
    EXPECT_STREQ("1001001100101100000001011010010", s1_2);
    EXPECT_STREQ("11145401322", s1_8);
    EXPECT_STREQ("499602d2", s1_16);
}

TEST(C5, Q6_itoa_width_p){
    int n0 = INT_MIN;
    char s0[1024];
    itoa_width_p(n0, s0, 15);
    EXPECT_STREQ("    -2147483648", s0);

    int n1 = INT_MAX;
    char s1[1024];
    itoa_width_p(n1, s1, 15);
    EXPECT_STREQ("     2147483647", s1);

    int n2 = 0;
    char s2[1024];
    itoa_width_p(n2, s2, 2);
    EXPECT_STREQ(" 0", s2);

    int n3 = -1024;
    char s3[1024];
    itoa_width_p(n3, s3, 5);
    EXPECT_STREQ("-1024", s3);
}

TEST(C5, Q6_strindex_p){
    char s0[] = "1234567";
    char t0[] = "345";
    EXPECT_EQ(2, strindex_p(s0, t0));

    char s1[] = "1234567";
    char t1[] = "567";
    EXPECT_EQ(4, strindex_p(s1, t1));

    char s2[] = "1234567";
    char t2[] = "5678";
    EXPECT_EQ(-1, strindex_p(s2, t2));

    char s3[] = "1234567";
    char t3[] = "89";
    EXPECT_EQ(-1, strindex_p(s3, t3));

    char s4[] = "";
    char t4[] = "";
    EXPECT_EQ(-1, strindex_p(s4, t4));

    char s5[] = "1234567";
    char t5[] = "";
    EXPECT_EQ(-1, strindex_p(s5, t5));
}

TEST(C5, Q8_day_of_year){
    EXPECT_EQ(-1, day_of_year(-1, 9, 10));
    EXPECT_EQ(-1, day_of_year(1989, -1, 10));
    EXPECT_EQ(-1, day_of_year(1989, 9, -1));
    EXPECT_EQ(-1, day_of_year(1800, 2, 29));
    EXPECT_EQ(-1, day_of_year(1800, 13, 13));
}

TEST(C5, Q8_month_day){
    int month;
    int day;
    month_day(-1, 188, &month, &day);
    EXPECT_EQ(-1, month);
    month_day(1989, 366, &month, &day);
    EXPECT_EQ(-1, month);
    month_day(2020, 367, &month, &day);
    EXPECT_EQ(-1, month);
}