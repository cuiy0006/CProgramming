#include <getline.h>
#include <printline.h>
#include <stdio.h>

#define MAXLINE 1000

int main(){
    char s[MAXLINE];
    int len;
    while((len = getline(s, MAXLINE)) != 0){
        printf("%d: ", len);
        printline(s, MAXLINE);
        putchar('\n');
    }
}