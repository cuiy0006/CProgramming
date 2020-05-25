#include <stdio.h>

#define LINESIZE 20
#define MAXLINESIZE 30

int main(){
    char c;
    int i = 0;
    while((c = getchar()) != EOF){
        if(c == '\n'){
            putchar('\n');
            i = 0;
            continue;
        }

        if(i < LINESIZE - 1){
            putchar(c);
            ++i;
        } else {
            if(c == ' ' || c == '\t'){
                putchar('\n');
                i = 0;
            } else {
                if(i < MAXLINESIZE){
                    putchar(c);
                    ++i;
                } else {
                    putchar('\n');
                    putchar(c);
                    i = 1;
                }
            }
        }
    }
}