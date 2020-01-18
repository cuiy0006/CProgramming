#include "expand.h"

void expand(char s1[], char s2[]){
    int i = 0;
    int j = 0;
    while(s1[i] != '\0'){
        if(s1[i] == '-'){
            if(i == 0 || s1[i + 1] == '\0' || s1[i - 1] == '-' || s1[i + 1] == '-'){
                s2[j] = '-';
                ++i;
                ++j;
            } else {
                for(char c = s1[i - 1] + 1; c < s1[i + 1]; ++c){
                    s2[j++] = c; 
                }
                ++i;
            }
        } else {
            s2[j++] = s1[i++];
        }
    }
    s2[j] = '\0';
}