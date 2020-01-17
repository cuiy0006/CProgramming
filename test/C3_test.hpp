#include "gtest/gtest.h"
#include <string.h>
#include <iostream>
#include "../C3/3-1/binsearch.h"
#include "../C3/3-2/escape.h"

void printStr(char s[]){
    int i = 0;
    while(s[i] != '\0'){
        putchar(s[i++]);
    }
    printf("\n-----------------------------------\n");
}

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
    EXPECT_TRUE(strcmp(t1, expect1));
    EXPECT_TRUE(strcmp(t2, s));
}