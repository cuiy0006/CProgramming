#include "itob.h"
#include "util.h"

void itob(int n, char s[], int b){
    int i = 0;
    int sign = 1;
    if(n < 0){
        s[i++] = '-';
        sign = -1;
    } else if(n == 0){
        s[i++] = '0';
    }
    
    while(n != 0){
        int remainder = n % b * sign;
        if(remainder > 9){
            s[i++] = remainder - 10 + 'a';
        } else {
            s[i++] = remainder + '0';
        }
        n = n / b;
    }
    s[i] = '\0';

    if(s[0] == '-'){
        reverse(s, 1, i - 1);
    } else {
        reverse(s, 0, i - 1);
    }
}