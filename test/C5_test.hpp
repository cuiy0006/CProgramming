#include "gtest/gtest.h"
#include "../C5/5-3/strcat_p.h"

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

