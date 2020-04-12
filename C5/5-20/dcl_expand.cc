// COPY SOLUTION


#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXTOKEN 100

enum {NAME, PARENS, BRACKETS};
enum {NO, YES};

void dcl(void);
void dirdcl(void);
int gettoken(void);
void errmsg(const char*);
// int tokentype;
// char token[MAXTOKEN];
// char name[MAXTOKEN];
// char datatype[MAXTOKEN];
// char out[1000];
// bool errored = false;

int tokentype;
char token[MAXTOKEN];
char name[MAXTOKEN];
char datatype[MAXTOKEN];
char out[1000];
extern int prevtoken;


int main(){
    while(gettoken() != EOF){
        strcpy(datatype, token);
        out[0] = '\0';
        dcl();
        if(tokentype != '\n')
            printf("syntax error\n");
        printf("%s: %s %s\n", name, out, datatype);
    }
    return 0;
}


void dcl(void){
    int ns;
    for(ns = 0; gettoken() == '*';)
        ns++;
    dirdcl();
    while(ns-- > 0)
        strcat(out, " pointer to");
}


void dirdcl(void){
    int type;
    void parmdcl(void);

    if(tokentype == '('){
        dcl();
        if(tokentype != ')')
            errmsg("error: missing )\n");
    } else if(tokentype == NAME)
        if(name[0] == '\0')
            strcpy(name, token);
    else
        errmsg("error: expected name or (dcl)\n");
    while((type = gettoken()) == PARENS || type == BRACKETS || type == '('){
        if(type == PARENS)
            strcat(out, " function returning");
        else if(type == '('){
            strcat(out, "function expecting");
            parmdcl();
            strcat(out, " and returning");
        } else {
            strcat(out, " array");
            strcat(out, token);
            strcat(out, " of");
        }
    }
}

void errmsg(const char* msg){
    prevtoken = YES;
    printf("%s", msg);
}