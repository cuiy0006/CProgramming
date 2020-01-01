#include <getline.h>
#include <stdio.h>

int getline(char s[], int lim){
    int i = 0;
    char c;
    while((c = getchar()) != EOF && c != '\n' && i < lim - 1){
        s[i] = c;
        ++i;
    }

    if(c == '\n'){
        s[i] = c;
        ++i;
    }

    s[i] = '\0';
    return i;
}