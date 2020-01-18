#include "escape.h"


void escape(char s[], char t[]){
    int i = 0;
    int j = 0;
    while(s[i] != '\0'){
        switch (s[i])
        {
        case '\n':
            t[j++] = '\\';
            t[j++] = 'n';
            break;
        case '\t':
            t[j++] = '\\';
            t[j++] = 't';
            break;
        default:
            t[j++] = s[i];
            break;
        }
        ++i;
    }
    t[j] = '\0';
}

void escape_reverse(char s[], char t[]){
    int i = 0;
    int j = 0;
    while(s[i] != '\0'){
        switch (s[i])
        {
        case '\\':
            ++i;
            if(s[i] == 't'){
                t[j++] = '\t';
            } else if(s[i] == 'n'){
                t[j++] = '\n';
            }
            break;
        
        default:
            t[j++] = s[i];
            break;
        }
        ++i;
    }
    t[j] = '\0';
}