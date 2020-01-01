#include <printline.h>
#include <stdio.h>

void printline(char s[], int lim){
    for(int i = 0; i < lim; ++i){
        if(s[i] == '\0'){
            break;
        }
        putchar(s[i]);
    }
}