#include "../../util/util.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "config.h"
#include <ctype.h>


#define MAXOP 100
#define MAXL 1000

int getop(char s[], char l[], int* j);
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
    char l[MAXL];
    int len;
    double vars[26];
    double last;

    while((len = getline(l, MAXL)) != 0){
        int start = 0;
        while(start < len && (type = getop(s, l, &start)) != EOF){
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
                }
                else
                    printf("error: unknown command %s\n", s);
                break;
            default:
                printf("error: unknown command %s\n", s);
                break;
            }
        }
    }
    return 0;
}
