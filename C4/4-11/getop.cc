#include <ctype.h>
#include <stdio.h>

#define NUMBER '0'

int getch(void);
void ungetch(int c);

int getop(char s[]){
    static int buf = 0;
    int i, c;
    if(buf == 0 || buf == ' ' || buf == '\t'){
        while((s[0] = c = getch()) == ' ' || c == '\t')
            ;
    } else {
        s[0] = c = buf;
    }
    buf = 0;

    s[1] = '\0';
    if(!isdigit(c) && c != '.')
        return c;
    i = 0;
    if(isdigit(c))
        while(isdigit(s[++i] = c = getch()) || c == '.')
            ;
    s[i] = '\0';
    if(c != EOF)
        buf = c;
    return NUMBER;
}