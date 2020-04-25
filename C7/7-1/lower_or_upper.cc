#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char *argv[]){
    if(argc != 2)
        return 0;
    
    char* cmd = argv[1];
    bool is_to_upper = true;
    if(strcmp(cmd, "toupper") == 0)
        is_to_upper = true;
    else if(strcmp(cmd, "tolower") == 0)
        is_to_upper = false;
    else
        return 0;

    int c;
    while((c = getchar()) != EOF){
        if(is_to_upper)
            putchar(toupper(c));
        else
            putchar(tolower(c));
    }
    return 0;
}