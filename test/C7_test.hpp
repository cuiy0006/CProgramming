#include "gtest/gtest.h"
#include "../C7/7-6/diff_file.h"

TEST(C7, Q1){
    char diff_line1[1000];
    char diff_line2[1000];
    EXPECT_FALSE(diff_file("../test/resources/filea0", "../test/resources/filea1", diff_line1, diff_line2));

    EXPECT_TRUE(diff_file("../test/resources/fileb0", "../test/resources/fileb1", diff_line1, diff_line2));
    EXPECT_STREQ("The San Francisco-based company also will furlough about 5% of employees who handle operations that have been suspended \n", diff_line1);
    EXPECT_STREQ("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa\n", diff_line2);

    EXPECT_TRUE(diff_file("../test/resources/filec0", "../test/resources/filec1", diff_line1, diff_line2));
}