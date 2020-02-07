#include "getline_p.h"
#include <stdio.h>

int getline(char* s, int lim){
    int i = 0;
    char c;
    while((c = getchar()) != EOF && c != '\n' && i < lim - 1){
        *s++ = c;
        ++i;
    }

    if(i < lim - 1 && c == '\n'){
        *s++ = c;
        ++i;
    }

    *s = '\0';
    return i;
}