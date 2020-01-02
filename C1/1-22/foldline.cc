#include <stdio.h>

#define LINESIZE 20

int main(){
    char c;
    int i = 0;
    while((c = getchar()) != EOF){
        if(c == '\n'){
            putchar('\n');
            i = 0;
            continue;
        }

        if(i < LINESIZE){
            putchar(c);
            ++i;
        } else {
            if(c == ' ' || c == '\t'){
                continue;
            } else {
                putchar('\n');
                putchar(c);
                i = 1;
            }
        }
    }
}