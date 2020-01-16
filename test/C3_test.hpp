#include "gtest/gtest.h"
#include <string.h>
#include <iostream>
#include "../C3/3-1/binsearch.h"


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

    int v3[] = {1, 2, 3, 3, 3, 6, 7};
    EXPECT_EQ(2, binsearch(3, v3, 7));
}