#include <stdio.h>
#include "getline.h"

#define MAXLINE 1000

int main(){
    char s[MAXLINE];
    int len;
    while((len = getline(s, MAXLINE)) != 0){
        printf("%d: %s\n", len, s);
    }
}