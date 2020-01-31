#include <ctype.h>
#include <stdio.h>

int getch(void);
void ungetch(int);

int getint(int *pn){
    int c, sign;

    while(isspace(c = getch()))
        ;
    
    if(!isdigit(c) && c != EOF && c != '+' && c != '-'){
        ungetch(c);
        return 0;
    }

    if(c == '+' || c =='-'){
        sign = c;
        c =  getch();
    } else {
        sign = -1;
    }

    if(!isdigit(c)){
        if(!isspace(c))
            return -1;
        if(sign == '-' || sign == '+')
            ungetch(sign);
        return 0;
    }
    
    for(*pn = 0; isdigit(c); c = getch())
        *pn = 10 * *pn + (c - '0');

    *pn *= (sign == '-'? -1 : 1);
    if(c != EOF)
        ungetch(c);
    return c;
}