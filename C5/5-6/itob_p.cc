#include "itob_p.h"
#include "reverse_p.h"

void itob_p(int n, char* s, int b){
    char* p = s;
    int sign = 1;
    if(n < 0){
        *p++ = '-';
        sign = -1;
    } else if(n == 0){
        *p++ = '0';
    }
    
    while(n != 0){
        int remainder = n % b * sign;
        if(remainder > 9){
            *p++ = remainder - 10 + 'a';
        } else {
            *p++ = remainder + '0';
        }
        n = n / b;
    }
    *p = '\0';

    if(*s == '-'){
        reverse_p(s + 1);
    } else {
        reverse_p(s);
    }
}