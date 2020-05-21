#include <stdio.h>

main(){
    int c;
    while(((c = getchar()) != EOF) == 1){
        putchar(c);
    }
    if((c != EOF) == 0)
        printf("verified!\n");
    else
        printf("unverified!\n");
}