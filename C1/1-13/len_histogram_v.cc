#include <stdio.h>

int main(){
    int idx = 0;
    int length = 0;
    char c;
    while((c = getchar()) != EOF){
        if(c == ' ' || c == '\t' || c == '\n'){
            if(length != 0){
                printf("%d: ", idx);
                for(int i = 0; i < length; ++i){
                    putchar('\n');
                    putchar('*');
                }
                putchar('\n');
                length = 0;
                ++idx;
            }
        } else {
            ++length;
        }
    }
}