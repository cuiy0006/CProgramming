#include <getline.h>
#include <stdio.h>

#define TABSIZE 7

int getline(char s[], int lim){
    int i = 0;
    int offset = 0;
    char c;
    while((c = getchar()) != EOF && c != '\n' && i < lim - 1){
        if(c == '\t'){
            int j = i - 1;
            while(j >= i - TABSIZE + 1 && s[j] == ' '){
                --j;
            }
            if(j == i - 1 && offset == TABSIZE - 1){
                s[j + 1] = ' ';
            } else {
                s[j + 1] = '|';
            }
            i = j + 2;
            offset = 0;
            continue;
        }
        if(offset == TABSIZE - 1 && c == ' '){
            int j = i - 1;
            while(j >= i - TABSIZE + 1 && s[j] == ' '){
                --j;
            }
            if(j < i - 1){
                s[j + 1] = '|'; // | -> \t
            } else {
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

    if(c == '\n'){
        s[i] = c;
        ++i;
    }

    s[i] = '\0';
    return i;
}