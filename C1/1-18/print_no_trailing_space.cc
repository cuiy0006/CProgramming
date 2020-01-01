#include <getline.h>
#include <printline.h>
#include <remove_trailing_space.h>
#include <stdio.h>

#define MAXLINE 1000

int main(){
    char s[MAXLINE];
    int len;
    while(getline(s, MAXLINE) != 0){
        len = remove_trailing_space(s);
        if(len <= 1){
            continue;
        }
        printf("%d: ", len);
        printline(s, MAXLINE);
        putchar('\n');
    }
}