#include <stdio.h>
#include <time.h>

void test_regular_speed(int& cnt);

int main(){
    int cnt = 0;
    clock_t start, end;
    start = clock();
    test_regular_speed(cnt);
    end = clock();
    printf("For regualr job: count of char read is %d, execution time is %ld\n", cnt, end - start);

    return 0;
}