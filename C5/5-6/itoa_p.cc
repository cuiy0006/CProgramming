#include "itoa_p.h"
#include "reverse_p.h"
#include "util.h"

void itoa_p(int n, char* s){
    char* p = s;
    int sign;
    if((sign = n) < 0)
        n = -n;
    
    do{
        *p++ = n % 10 + '0';
    } while((n /= 10) > 0);
    if(sign < 0)
        *p++ = '-';
    *p = '\0';
    reverse_p(s);
}