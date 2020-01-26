#include "stdio.h"

int getch(void);
void ungetch(int c);
void ungets(char s[]);

int main(){
    char s[] = "abcd";
    ungets(s);
    char c;
    while((c = getch()) != EOF){
        putchar(c);
    }
}