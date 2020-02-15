#include "getline.h"
#include <stdio.h>

#define TABSIZE 7

int getline(char s[], int lim){
    int i = 0;
    int offset = 0;
    char c;
    while((c = getchar()) != EOF && c != '\n' && i < lim - 1){
        if(c == '\t' || (offset == TABSIZE - 1 && c == ' ')){
            int j = i - 1;
            while(j >= i - TABSIZE + 1 && s[j] == ' '){
                --j;
            }
            s[j + 1] = '|';
            if(j == i - 1){
                if(c == ' ' || (c == '\t' && offset == TABSIZE - 1))
                    s[j + 1] = ' ';
            }
            i = j + 2;
            offset = 0;
            continue;
        }
        s[i] = c;
        ++i;
        ++offset;
        offset = offset % TABSIZE;
    }

    if(i < lim - 1 && c == '\n'){
        s[i++] = c;
    }

    s[i] = '\0';
    return i;
}