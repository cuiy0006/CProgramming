#include <ctype.h>
#include <stdio.h>

int getch(void);
void ungetch(int);

int getfloat(double *pn){
    int c, sign;
    int power;
    double dpart;

    while(isspace(c = getch()))
        ;
    
    if(!isdigit(c) && c != EOF && c != '+' && c != '-'){
        ungetch(c);
        return 0;
    }

    sign = (c == '-') ? -1 : 1;
    if(c == '+' || c == '-')
        c = getch();
    
    for(*pn = 0; isdigit(c); c = getch())
        *pn = 10 * *pn + (c - '0');

    if(c == '.')
        c = getch();
    
    for(power = 10, dpart = 0; isdigit(c); c = getch()){
        dpart = dpart + (double)(c - '0') / power;
        power *= 10;
    }

    if(c != EOF)
        ungetch(c);

    *pn = sign * (*pn + dpart);

    return c;
}