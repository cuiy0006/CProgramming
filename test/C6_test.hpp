#include "gtest/gtest.h"
#include "../C6/6-5/undef.h"

TEST(C6, Q5){
    char n0[] = "1234";
    char n1[] = "12345";
    char n2[] = "abcdef12345";
    char n3[] = "myname";

    char v0[] = "__1234";
    char v1[] = "__12345";
    char v2[] = "__abcdef12345";

    install(n0, v0);
    install(n1, v1);
    install(n2, v2);

    struct nlist* np = lookup(n0);
    EXPECT_STREQ(n0, np->name);
    EXPECT_STREQ(v0, np->defn);

    np = lookup(n1);
    EXPECT_STREQ(n1, np->name);
    EXPECT_STREQ(v1, np->defn);

    np = lookup(n2);
    EXPECT_STREQ(n2, np->name);
    EXPECT_STREQ(v2, np->defn);

    EXPECT_EQ(-1, undef(n3));

    EXPECT_EQ(0, undef(n1));
    np = lookup(n1);
    EXPECT_EQ(NULL, np);

    EXPECT_EQ(-1, undef(n1));

    EXPECT_EQ(0, undef(n0));
    np = lookup(n0);
    EXPECT_EQ(NULL, np);

    EXPECT_EQ(0, undef(n2));
    np = lookup(n2);
    EXPECT_EQ(NULL, np);
}