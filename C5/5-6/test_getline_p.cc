#include "getline_p.h"
#include "stdio.h"

#define MAXLINE 1000

int main(){
    char s[MAXLINE];
    while(getline(s, MAXLINE) != 0){
        int i = 0;
        while(*(s + i) != '\0'){
            putchar(*(s + i));
            ++i;
        }
    }
}