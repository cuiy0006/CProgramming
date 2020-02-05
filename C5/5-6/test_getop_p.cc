#include "getop_p.h"
#include "../../util/util.h"
#include <stdio.h>

int main(){
    int ret;
    char s[100];
    while(ret = getop_p(s)){
        putchar(ret);
        putchar(':');
        printStr(s);
    }
}