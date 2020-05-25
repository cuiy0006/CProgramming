#include <stdio.h>

#define NASCII 128

int main(){
    int freq[NASCII] = {0};

    char c;
    while((c = getchar()) != EOF){
        if(c == ' ' || c == '\t' || c == '\n'){
            continue;
        } else {
            ++freq[c];
        }
    }

    for(int i = 0; i < NASCII; ++i){
        if(freq[i] == 0){
            continue;
        }
        printf("%c: ", i);
        for(int j = 0; j < freq[i]; ++j){
            putchar('*');
        }
        putchar('\n');
    }
}