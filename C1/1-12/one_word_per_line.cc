#include <stdio.h>

#define out 0
#define in 1

int main(){
    char c;
    int state = out;
    bool last_newline = true;
    while((c = getchar()) != EOF){
        if(c == ' ' || c == '\t' || c == '\n'){
            if(!last_newline){
                last_newline = true;
                putchar('\n');
            }
            state = out;
            continue;
        } else if(state == out){
            state = in;
        }
        putchar(c);
        last_newline = false;
    }
}