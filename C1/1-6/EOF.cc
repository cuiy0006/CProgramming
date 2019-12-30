#include <stdio.h>

main(){
    int c;
    while(((c = getchar()) != EOF) == 1){
        putchar(c);
    }
    putchar('0');
}