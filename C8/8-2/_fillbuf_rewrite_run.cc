#include "_fillbuf_rewrite.h"

void test_rewrite_speed(int& cnt){
    FILE* fp = fopen("../test/resources/medium_size_file", "r");
    cnt = 0;
    while(getc(fp) != EOF){
        cnt++;
    }
}