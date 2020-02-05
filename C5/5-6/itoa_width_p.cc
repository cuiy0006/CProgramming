#include "itoa_width_p.h"
#include "reverse_p.h"
#include "string.h"
#include "util.h"

void itoa_width_p(int n, char* s, int w){
    char* p = s;
    int sign = 1;
    if(n < 0){
        *p++ = '-';
        sign = -1;
    } else if(n == 0){
        *p++ = '0';
    }
    
    while(n != 0){
        *p++ = n % 10 * sign + '0';
        n = n / 10;
    }
    *p = '\0';

    if(*s == '-'){
        reverse_p(s + 1);
    } else {
        reverse_p(s);
    }

    pad_left(s, strlen(s), w, ' ');
}