#include "strcat_p.h"

void strcat_p(char* s, char* t){
    while(*s)
        s++;
    while(*s++ = *t++)
        ;
}