#include "gtest/gtest.h"
#include "../C8/8-6/calloc.h"
#include "../C8/8-7/malloc_2.h"
#include <stdio.h>


TEST(C8, MALLOC1){
    for(int i = 9999900; i < 10000000; i++){
        char* str = (char*)malloc_(i);

        EXPECT_TRUE(str != NULL);
        if(str == NULL)
            break;

        str[0] = 'a';
        str[1] = 'b';
        str[2] = 'c';
        str[3] = 'd';
        str[4] = '\0';
        EXPECT_STREQ("abcd", str);
        free_(str);
    }
}

TEST(C8, MALLOC2){
    char* str = (char*)malloc_(10000000);
    char* str1 = (char*)malloc_(10000001);
    char* str2 = (char*)malloc_(10000002);

    EXPECT_TRUE(str != NULL);
    EXPECT_TRUE(str1 != NULL);
    EXPECT_TRUE(str2 != NULL);

    free_(str1);
    free_(str);
    free_(str2);

    //printf("---------------------------Built first part-----------------------\n");

    char* str3 = (char*)malloc_(100);
    char* str4 = (char*)malloc_(1000);

    EXPECT_TRUE(str3 != NULL);
    EXPECT_TRUE(str4 != NULL);

    free_(str3);
    free_(str4);
}


TEST(C8, Q6){
    for(int i = 9999900; i < 10000000; i++){
        int* arr = (int*)calloc_(i, sizeof(int));

        EXPECT_TRUE(arr != NULL);
        if(arr == NULL)
            break;

        arr[0] = 1;
        arr[1] = 2;
        arr[2] = 3;
        arr[3] = 4;
        arr[4] = 5;
        free_(arr);
    }
}

typedef long Align;
union header {
    struct {
        union header* ptr;
        unsigned size;
    } s;
    Align x;
};

TEST(C8, Q7){
    char* str = (char*)malloc_2(10000000 + 1);
    EXPECT_TRUE(str == NULL);

    char* str1 = (char*)malloc_2(10000000);
    EXPECT_TRUE(str1 != NULL);
    header* hp = (header*)str1 - 1;
    hp->s.size = 1;
    free_2(str1);

    char* str2 = (char*)malloc_2(10000000);
    EXPECT_TRUE(str2 != NULL);
    hp = (header*)str2 - 1;
    hp->s.size += 1;
    free_2(str2);
}