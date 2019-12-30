#include <stdio.h>

#define out 0
#define in 1

int main(){
    char c;
    int state = out;
    int cc = 0, wc = 0, lc = 0;
    while((c = getchar()) != EOF){
        ++cc;
        if(c == ' ' || c == '\t' || c == '\n'){
            state = out;
        } else if(state == out){
            ++wc;
            state = in;
        }

        if(c == '\n'){
            ++lc;
        }
    }

    printf("cc: %d, wc: %d, lc: %d", cc, wc, lc);
}