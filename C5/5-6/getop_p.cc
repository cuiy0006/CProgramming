#include <ctype.h>
#include "stdio.h"
#include "getop_p.h"

#define NUMBER '0'

int getch(void);
void ungetch(int c);

int getop_p(char* s){
    int i, c;
    while((*s = c = getch()) == ' ' || c == '\t')
        ;

    *(s + 1) = '\0';
    if(!isdigit(c) && c != '.')
        return c;
    i = 0;
    if(isdigit(c))
        while(isdigit(*(++s) = c = getch()) || c == '.')
            ;
    *s = '\0';
    if(c != EOF)
        ungetch(c);
    return NUMBER;
}