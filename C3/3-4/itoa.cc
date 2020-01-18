#include "itoa.h"
#include <iostream>

void reverse(char s[], int start, int end){
    while(start < end){
        int tmp = s[start];
        s[start] = s[end];
        s[end] = tmp;
        ++start;
        --end;
    }
}

void itoa(int n, char s[]){
    int i = 0;
    int sign = 1;
    if(n < 0){
        s[i++] = '-';
        sign = -1;
    } else if(n == 0){
        s[i++] = '0';
    }
    
    while(n != 0){
        s[i++] = n % 10 * sign + '0';
        n = n / 10;
    }
    s[i] = '\0';

    if(s[0] == '-'){
        reverse(s, 1, i - 1);
    } else {
        reverse(s, 0, i - 1);
    }
}