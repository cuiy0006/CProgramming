#include <stdio.h>

#define BUFSIZE 100

char buf = 0;

int getch(void){
    if(buf == 0){
        return getchar();
    } else {
        char res = buf;
        buf = 0;
        return res;
    }
}

void ungetch(int c){
    if(buf != 0){
        printf("ungetch: too many characters\n");
    } else {
        buf = c;
    }
}