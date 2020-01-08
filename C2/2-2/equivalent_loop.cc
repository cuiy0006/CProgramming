#include <stdio.h>

int main(){
    const int lim = 10;
    char c;
    char s[lim];
    int i;
    for(i = 0; i < lim - 1; ++i){
        c = getchar();
        if(c == '\n'){
            break;
        }

        if(c == EOF){
            break;
        }

        s[i] = c;
    }

    s[i] = '\0';
    i = 0;
    while(s[i] != '\0'){
        putchar(s[i]);
        ++i;
    }
    putchar('\n');
}