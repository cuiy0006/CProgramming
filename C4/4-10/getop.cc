#include <ctype.h>
#include <stdio.h>
#include "config.h"

int getch(void);
void ungetch(int c);

int getop(char s[], char l[], int* j){
    int i, c, type;
    while((s[0] = c = l[(*j)++]) == ' ' || c == '\t')
        ;
    if(c == '\n')
        return '\n';
    --(*j);
    i = 0;
    if(!isdigit(c) && c != '.'){
        while((c = l[(*j)++]) != ' ' && c != '\t' && c != '\n'){
            s[i++] = c;
        }
        type = COMMAND;
    } else {
        while(isdigit(c = l[(*j)++]) || c == '.'){
            s[i++] = c;
        }
        type = NUMBER;
    }

    s[i] = '\0';
    if(c != EOF)
        --(*j);
    return type;
}