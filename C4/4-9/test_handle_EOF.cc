#include "stdio.h"

int getch(void);
void ungetch(int c);

int main(){
    char c;
    ungetch(EOF);
    ungetch('a');
    ungetch('b');
    ungetch('c');
    while((c = getch()) != EOF){
        putchar(c);
    }
}