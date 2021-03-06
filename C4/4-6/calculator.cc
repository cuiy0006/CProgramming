#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "config.h"
#include <ctype.h>

#define MAXOP 100

int getop(char []);
void push(double);
double pop(void);
double top(void);
void print_top(void);
void duplicate_top(void);
void swap_top_two(void);

main(){
    int type;
    double op2;
    char s[MAXOP];
    double vars[26];
    double last;

    while((type = getop(s)) != EOF){
        switch (type)
        {
        case '\n':
            last = pop();
            printf("\t%.8g\n", last);
            break;

        case NUMBER:
            push(atof(s));
            break;

        case COMMAND:
            if(strcmp(s, "+") == 0)
                push(pop() + pop());
            else if(strcmp(s, "*") == 0)
                push(pop() * pop());
            else if(strcmp(s, "-") == 0){
                op2 = pop();
                push(pop() - op2);
            } else if(strcmp(s, "/") == 0){
                op2 = pop();
                if(op2 != 0.0)
                    push(pop() / op2);
                else
                    printf("error: zero divisor\n");
            } else if(strlen(s) == 1 && s[0] >= 'a' && s[0] <= 'z'){
                push(vars[s[0] - 'a']);
            } else if(strlen(s) == 2 && s[0] >= 'a' && s[0] <= 'z' && s[1] == '='){
                vars[s[0] - 'a'] = top();
            } else if(strcmp(s, "last") == 0){
                push(last);
            }
            else
                printf("error: unknown command %s\n", s);
            break;
        default:
            printf("error: unknown command %s\n", s);
            break;
        }
    }
    return 0;
}
