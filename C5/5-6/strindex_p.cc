#include "strindex_p.h"

int strindex_p(char* s, char* t){
    if(*t == '\0')
        return -1;

    int i = 0;

    while(*s){
        char* s0 = s;
        char* t0 = t;
        while(*t0 && *t0 == *s0){
            ++t0;
            ++s0;
        }
        if(*t0 == '\0')
            return i;
        ++i;
        ++s;
    }
    return -1;
}
