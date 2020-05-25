#include "remove_trailing_space.h"

int remove_trailing_space(char s[]){
    int i = 0;
    bool newline = false;
    while(s[i] != '\0'){
        ++i;
    }
    --i;
    if(s[i] == '\n'){
        --i;
        newline = true;
    }
    while(i >= 0 && (s[i] == ' ' || s[i] == '\t')){
        --i;
    }
    if(newline){
        ++i;
        s[i] = '\n';
    }
    ++i;
    s[i] = '\0';
    return i; 
}