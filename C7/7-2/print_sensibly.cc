#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define WIDTH_HEX 5

int main(int argc, char *argv[]){
    if(argc != 2)
        return -1;

    int width = atoi(argv[1]);

    if(width < WIDTH_HEX)
        return -1;

    int idx = 0;
    int c;
    while((c = getchar()) != EOF){
        if(iscntrl(c)){
            if(idx + WIDTH_HEX > width){
                putchar('\n');
                idx = 0;
            }

            printf("\\0x%2.2x", c);
            idx += WIDTH_HEX;

            if(c == '\n')
                putchar(c);
        } else {
            if(idx + 1 > width){
                putchar('\n');
                idx = 0;
            }

            putchar(c);
            ++idx;
        }
    }

}