#include "str_op.h"
#include "stdio.h"

char *strncpy_p(char *dest, const char *src, size_t n){
    for(size_t i = 0; i < n && *src; ++i){
        *dest++ = *src++;
    }
    *dest = '\0';
    return dest;
}

char *strncat_p(char *dest, const char *src, size_t n){
    while (*dest){
        ++dest;
    }
    for(size_t i = 0; i < n && *src; ++i){
        *dest++ = *src++;
    }
    *dest = '\0';
    return dest;
}

int strncmp_p(const char *str1, const char *str2, size_t n){
    size_t i = 0;
    while(true){
        if(*str1 != *str2)
            break;
        if(i == n - 1 || *str1 == '\0')
            return 0;
        ++i;
        ++str1;
        ++str2;
    }
    return *str1 - *str2;
}