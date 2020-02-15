#include "getline.h"
#include <stdio.h>

#define TABSIZE 7

int getline(char s[], int lim){
    int i = 0;
    int offset = 0;
    char c;
    while((c = getchar()) != EOF && c != '\n' && i < lim - 1){
        if(c == '\t'){
            while(offset < TABSIZE && i < lim - 1){
                s[i] = ' ';
                ++i;
                ++offset;
            }
            offset = 0;
        } else {
            s[i] = c;
            ++i;
            ++offset;
            offset = offset % TABSIZE;
        }
    }

    if(c == '\n'){
        s[i] = c;
        ++i;
    }

    s[i] = '\0';
    return i;
}