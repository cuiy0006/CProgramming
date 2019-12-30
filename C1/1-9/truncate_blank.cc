#include <stdio.h>

int main(){
    char c;
    bool last_blank = false;
    while((c = getchar()) != EOF){
        if(c == ' '){
            if(last_blank){
                continue;
            }
            last_blank = true;
        } else {
            last_blank = false;
        }
        putchar(c);
    }
}