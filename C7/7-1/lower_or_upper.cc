#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char *argv[]){
    if(argc != 2)
        return -1;
    
    bool is_to_upper;
    if(strcmp(argv[1], "toupper") == 0)
        is_to_upper = true;
    else if(strcmp(argv[1], "tolower") == 0)
        is_to_upper = false;
    else
        return -1;

    int c;
    while((c = getchar()) != EOF){
        if(is_to_upper)
            putchar(toupper(c));
        else
            putchar(tolower(c));
    }
    return 0;
}