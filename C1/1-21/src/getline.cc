#include <getline.h>
#include <stdio.h>

#define TABSIZE 7

int getline(char s[], int lim){
    int i = 0;
    int offset = 0;
    char c;
    while((c = getchar()) != EOF && c != '\n' && i < lim - 1){
        s[i] = c;
        if(offset == TABSIZE - 1 && c == ' '){
            int j = i - 1;
            while(j >= 0 && s[j] == ' '){
                --j;
            }
            if(j < TABSIZE - 2){
                s[j + 1] = '*'; // * -> \t
                i = j + 1;
            }
        }
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