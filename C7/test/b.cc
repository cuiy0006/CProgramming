#include <stdio.h>

int a = 0;
static int b = 0;
int c = 0;


void incra(){
    a++;
}

void printa(){
    printf("a:%d\n", a);
}

void incrb(){
    b++;
}

void printb(){
    printf("b:%d\n", b);
}
