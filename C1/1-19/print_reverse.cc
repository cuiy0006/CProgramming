#include "reverseline.h"
#include "../../util/util.h"
#include <stdio.h>

#define MAXLINE 1000

int main(){
    char s[MAXLINE];
    int len;
    while((len = getline(s, MAXLINE)) != 0){
        reverseline(0, len - 1, s);
        printf("%d: ", len);
        printline(s, MAXLINE);
        putchar('\n');
    }
}