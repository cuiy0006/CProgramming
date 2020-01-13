#include <ctype.h>
#include "htoi.h"

int htoi(char h[]){
    int i = 0;
    if(*h == '0' && (*(h + 1) == 'x' || *(h + 1) == 'X')){
        i += 2;
    }
    int res = 0;
    char c;
    while((c = *(h + i)) != '\0'){
        int tmp;
        if(isdigit(c)){
            tmp = c - '0';
        } else {
            if(c >= 'a' && c <= 'f'){
                tmp = c - 'a' + 10;
            } else {
                tmp = c - 'A' + 10;
            }
        }
        res = 16 * res + tmp;
        ++i;
    }
    return res;
}