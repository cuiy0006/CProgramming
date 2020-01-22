#include <ctype.h>
#include <stdio.h>

#define NUMBER '0'
#define COMMAND '1'

int getch(void);
void ungetch(int c);

int getop(char s[]){
    int i, c, type;
    while((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    if(c == '\n')
        return '\n';
    ungetch(c);
    i = 0;
    if(!isdigit(c) && c != '.'){
        while((c = getch()) != ' ' && c != '\t' && c != '\n'){
            s[i++] = c;
        }
        type = COMMAND;
    } else {
        while(isdigit(c = getch()) || c == '.'){
            s[i++] = c;
        }
        type = NUMBER;
    }

    s[i] = '\0';
    if(c != EOF)
        ungetch(c);
    return type;
}