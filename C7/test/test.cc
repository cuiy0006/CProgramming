#include "a.h"
#include "b.h"
#include <stdio.h>

main(){
    printf("------------------------------begin-----------------------------\n");
    extern int c;
    c++;
    printf("c:%d\n", c);

    incra();
    printa();
    incrb();
    printb();
    printf("------------------------------end-----------------------------\n");
    go();
}