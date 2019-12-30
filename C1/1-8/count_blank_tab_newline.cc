#include <stdio.h>

main(){
    int blank_count = 0;
    int tab_count = 0;
    int newline_count = 0;

    char c;
    while((c = getchar()) != EOF){
        if(c == ' '){
            ++blank_count;
        } else if(c == '\t'){
            ++tab_count;
        } else if(c == '\n'){
            ++newline_count;
        }
    }

    printf("blank count: %d, tab count: %d, newline count: %d", blank_count, tab_count, newline_count);
}