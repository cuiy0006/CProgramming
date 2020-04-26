#include <stdio.h>

#define BUFSIZE 100

char buf[BUFSIZE];
char bufp = 0;

int getch(void){
    if(bufp > 0)
        return buf[--bufp];
    else{
        char c;
        scanf("%c", &c);
        return c;
    }
}

void ungetch(int c){
    if(bufp >= BUFSIZE){
        printf("ungetch: too many characters\n");
    } else {
        buf[bufp++] = c;
    }
}