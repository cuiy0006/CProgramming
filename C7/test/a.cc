#include "a.h"
#include "b.h"
#include <stdio.h>

void go(){
    incra();
    printa();
    incrb();
    printb();

    extern int c;
    c += 1;
    printf("c:%d\n", c);

}