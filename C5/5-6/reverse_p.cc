#include "reverse_p.h"
#include <string.h>
#include "stdio.h"
#include "util.h"

void reverse_p(char* s){
    char* e = s;
    while(*e)
        ++e;
    --e;

    while(s < e){
        char tmp = *s;
        *s = *e;
        *e = tmp;
        --e;
        ++s;
    }
}