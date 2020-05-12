#include <stdio.h>

void test_rewrite_speed(int& cnt);

int main(){
    int cnt = 0;
    test_rewrite_speed(cnt);
    printf("Count of chars read is %d\n", cnt);
}