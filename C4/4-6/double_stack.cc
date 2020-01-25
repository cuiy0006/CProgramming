#include "stdio.h"

#define MAXVAL 100

int sp = 0;
double val[MAXVAL];

void push(double f){
    if(sp < MAXVAL){
        val[sp++] = f;
    } else {
        printf("error: stack full, cann't push %g\n", f);
    }
}

double pop(void){
    if(sp > 0){
        return val[--sp];
    } else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

double top(void){
    if(sp > 0){
        return val[sp - 1];
    } else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

void print_top(void){
    if(sp == 0){
        printf("error: stack empty\n");
        return;
    }
    printf("%lf\n", val[sp - 1]);
}

void duplicate_top(void){
    if(sp == 0){
        printf("error: stack empty\n");
        return;
    }
    push(val[sp - 1]);
}

void swap_top_two(void){
    if(sp < 2){
        printf("error: not enough elements in stack\n");
        return;
    }
    double tmp = val[sp - 1];
    val[sp - 1] = val[sp - 2];
    val[sp - 2] = tmp;
}