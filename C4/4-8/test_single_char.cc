#include "stdio.h"

int getch(void);
void ungetch(int c);

int main(){
    char c;
    ungetch('a');
    ungetch('b');
    c = getch();
    putchar(c);
    ungetch('c');
    while((c = getch()) != EOF){
        putchar(c);
    }
}