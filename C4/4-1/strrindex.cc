#include "strrindex.h"

int strrindex(char s[], char t[]){
    int i = 0;
    while(s[i] != '\0'){
        ++i;
    }
    --i;
    while(i >= 0){
        if(s[i] == t[0]){
            int m = i;
            int n = 0;
            while(t[n] != '\0' and s[m] == t[n]){
                ++m;
                ++n;
            }
            if(t[n] == '\0'){
                return i;
            }
        }
        --i;
    }
    return -1;
}