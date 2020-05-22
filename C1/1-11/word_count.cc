#include <stdio.h>

#define in 1
#define out 0

int main(){
    char c, nl, nw, nc, state;

    state = out;
    nl = nw = nc = 0;
    while((c = getchar()) != EOF){
        ++nc;

        if(c == '\n'){
            ++nl;
        }
        if(c == ' ' || c == '\t' || c == '\n'){
            state = out;
        } else if(state == out){
            ++nw;
            state = in;
        }
    }

    printf("char count: %d, word count: %d, line count: %d\n", nc, nw, nl);
}

// one-line input without \n