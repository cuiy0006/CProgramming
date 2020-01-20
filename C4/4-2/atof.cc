#include "atof.h"
#include "ctype.h"
#include "util.h"
#include <math.h>

double atof(char s[]){
    double val, power;
    int i, sign;
    int e = 0;
    for(i = 0; isspace(s[i]); ++i)
        ;
    sign = (s[i] == '-') ? -1: 1;
    if(s[i] == '+' || s[i] == '-')
        ++i;
    for(val = 0.0; isdigit(s[i]); ++i)
        val = 10.0 * val + (s[i] - '0');
    if(s[i] == '.')
        ++i;
    for(power = 1.0; isdigit(s[i]); ++i){
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }
    if(s[i] == 'e'){
        ++i;
        e = atoi(s, i);
    }

    return sign * val / power * pow(10, e);
}