#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include "../../util/stream_op.h"
#include "../../util/util.h"
#include "../6-5/undef.h"

#define MAXWORD 1000
#define MAXKEY 100
#define MAXVALUE 900

bool is_valid(char c);
void do_define(char* line, int len, int i);
void do_undef(char* line, int len, int i);

main(){
    int len;
    char line[MAXWORD];
    while((len = getline(line, MAXWORD)) != 0){
        int i = 0;
        while(i < len && !is_valid(line[i]))
            ++i;

        char define[8];
        strncpy(define, line + i, 6);
        define[6] = '\0';

        if(strcmp(define, "#undef") == 0)
            do_undef(line, len, i + 6);

        strncpy(define, line + i, 7);
        define[7] = '\0';

        if(strcmp(define, "#define") == 0)
            do_define(line, len, i + 7);
    }
}


bool is_valid(char c){
    return c != '\n' && c != '\0' &&  c != '\t' && !isspace(c);
}

void do_define(char* line, int len, int i){
    while(i < len && !is_valid(line[i]))
        ++i;

    char key[MAXKEY];
    int j = 0;
    while(i < len && j < MAXKEY && is_valid(line[i]))
        key[j++] = line[i++];

    if(j == MAXWORD || j == 0)
        return;
    
    key[j] = '\0';

    while(i < len && !is_valid(line[i]))
        ++i;

    j = 0;
    char value[MAXVALUE];
    while(i < len && j < MAXVALUE && line[i] != '\n' && line[i] != '\0')
        value[j++] = line[i++];

    --j;
    while(isspace(value[j]) || value[j] == '\t')
        --j;
    ++j;

    if(j == MAXVALUE || j == 0)
        return;

    value[j] = '\0';

    install(key, value);
}

void do_undef(char* line, int len, int i){
    while(i < len && !is_valid(line[i]))
        ++i;

    char key[MAXKEY];
    int j = 0;
    while(i < len && j < MAXKEY && is_valid(line[i]))
        key[j++] = line[i++];

    if(j == MAXWORD || j == 0)
        return;
    
    key[j] = '\0';
    while(i < len){
        if(is_valid(line[i]))
            return;
        ++i;
    }

    undef(key);
}