#include "squeeze.h"

void squeeze(char s1[], char s2[]){
    bool exist[128];
    for(int i = 0; i < 128; ++i){
        exist[i] = false;
    }

    char c;
    int i = 0;
    while((c = s2[i]) != '\0'){
        exist[c] = true;
        ++i;
    }

    i = 0;
    int j = 0;
    while((c = s1[i]) != '\0'){
        if(!exist[c]){
            s1[j++] = c;
        }
        ++i;
    }
    s1[j] = '\0';
}