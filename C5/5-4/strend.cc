#include "strend.h"

int strend(char* s, char* t){
    char* i = s;
    char* j = t;

    while(*i){
        ++i;
    }
    while(*j){
        ++j;
    }
    while(j != t){
        if(i < s || *i-- != *j--)
            return 0;
    }
    return 1;
}