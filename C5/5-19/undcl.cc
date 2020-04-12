#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "../../util/stream_op.h"

#define MAXTOKEN 100

enum {NAME, PARENS, BRACKETS};
bool starred = false;
char token[MAXTOKEN];
char out[1000];
int tokentype;
int gettoken(void);

int gettoken(void){
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

main(){
    int type;
    char temp[MAXTOKEN];

    while(gettoken() != EOF){
        strcpy(out, token);
        while ((type = gettoken()) != '\n')
        {
            if(type == PARENS || type == BRACKETS){
                if(starred){
                    sprintf(temp, "(%s)%s", out, token);
                    strcpy(out, temp);
                    starred = false;
                } else
                    strcat(out, token);
            }
            else if(type == '*'){
                starred = true;
                sprintf(temp, "*%s", out);
                strcpy(out, temp);
            }
            else if(type == NAME){
                sprintf(temp, "%s %s", token, out);
                strcpy(out, temp);
            }
            else
                printf("invalid input at %s\n", token);
            printf("%s\n", out);
        }
        return 0;
    }
}