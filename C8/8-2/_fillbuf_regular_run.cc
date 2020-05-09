#include "_fillbuf_regular.h"

void test_regular_speed(int& cnt){
    FILE* fp = fopen("../test/resources/medium_size_file", "r");
    cnt = 0;
    while(getc(fp) != EOF){
        cnt++;
    }
}