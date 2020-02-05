#include "atoi_p.h"
#include "ctype.h"

int atoi_p(char* s){
    int n, sign;
    while(isspace(*s))
        ++s;
    sign = (*s == '-') ? -1: 1;
    if(*s == '+' || *s == '-')
        ++s;
    for(n = 0; isdigit(*s); ++s)
        n = 10 * n + (*s - '0');
    return sign * n;
}