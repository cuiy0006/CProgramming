#include <stdio.h>

#define BUFSIZE 100

char buf[BUFSIZE];
char bufp = 0;

int getch(void){
    return (bufp > 0) ? buf[--bufp]: getchar();
}

void ungetch(int c){
    if(bufp >= BUFSIZE){
        printf("ungetch: too many characters\n");
    } else {
        buf[bufp++] = c;
    }
}

void ungets(char s[]){
    int i = 0;
    while(s[i] != '\0'){
        ++i;
    }
    --i;
    while(i >= 0){
        ungetch(s[i]);
        --i;
    }
}