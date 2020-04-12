#include <string.h>
#include <ctype.h>
#include "../../util/stream_op.h"


enum {NAME, PARENS, BRACKETS};
enum {NO, YES};
extern int tokentype;
extern char token[];
int prevtoken = NO;

int gettoken(void){
    if(prevtoken){
        prevtoken = NO;
        return tokentype;
    }
    int c;
    char* p = token;
    while((c = getch()) == ' ' || c == '\t')
        ;
    if(c == '('){
        if((c = getch()) == ')'){
            strcpy(token, "()");
            return tokentype = PARENS;
        } else {
            ungetch(c);
            return tokentype = '(';
        }
    } else if(c == '['){
        for(*p++ = c; (*p++ = getch()) != ']';)
            ;
        *p = '\0';
        return tokentype = BRACKETS;
    } else if(isalpha(c)){
        for(*p++ = c; isalnum(c = getch());)
            *p++ = c;
        *p = '\0';
        ungetch(c);
        return tokentype = NAME;
    } else
        return tokentype = c;
}