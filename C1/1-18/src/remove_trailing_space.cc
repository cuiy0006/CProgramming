#include <remove_trailing_space.h>

int remove_trailing_space(char s[]){
    int i = 0;
    while(s[i] != '\0'){
        ++i;
    }
    --i;
    --i;
    while(i >= 0 && (s[i] == ' ' || s[i] == '\t')){
        --i;
    }
    ++i;
    s[i] = '\n';
    ++i;
    s[i] = '\0';
    return i; 
}