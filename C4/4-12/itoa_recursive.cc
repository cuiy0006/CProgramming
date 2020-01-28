#include "itoa_recursive.h"
#include "util.h"

int helper(int n, char s[], int i, int sign){
    if(n == 0){
        return i;
    }

    s[i] = n % 10 * sign + '0';
    return helper(n / 10, s, i + 1, sign);
}

void itoa_recursive(int n, char s[]){
    int i = 0;
    int sign = 1;
    if(n < 0){
        s[i++] = '-';
        sign = -1;
    } else if(n == 0){
        s[i++] = '0';
    }
    
    i = helper(n, s, i, sign);
    s[i] = '\0';

    if(s[0] == '-'){
        reverse(s, 1, i - 1);
    } else {
        reverse(s, 0, i - 1);
    }
}