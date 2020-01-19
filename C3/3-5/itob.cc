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
        int reminder = n % b * sign;
        if(reminder > 9){
            s[i++] = reminder - 10 + 'a';
        } else {
            s[i++] = reminder + '0';
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