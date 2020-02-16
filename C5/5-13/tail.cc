#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "../../util/util.h"
#include "../../util/memory_op.h"

#define N 10
#define MAXLINE 1000
#define MAXLEN 1000

void writelines(char* lineptr[], int nlines, int start_index);

main(int argc, char *argv[]){
    int n = N;
    ++argv;
    if(--argc > 0){
        if(**argv == '-'){
            char* p = *argv + 1;
            if(*p == '\0'){
                printf("Usage: tail -n\n");
                return 0;
            }
            while(*p != '\0'){
                if(!isdigit(*p)){
                    printf("Usage: tail -n\n");
                    return 0;
                }
                ++p;
            }
            n = atoi(*argv + 1);
        } else {
            printf("Usage: tail -n\n");
            return 0;
        }
    }

    char *lines[MAXLEN];
    char s[MAXLINE];
    int len;
    int i = 0;
    while((len = getline(s, MAXLINE)) != 0){
        if(s[len - 1] == '\n')
            s[--len] = '\0';
        char* p;    
        if(i >= MAXLEN || (p = alloc(len + 1)) == NULL){
            printf("Too many lines\n");
            return 0;
        }
        strcpy(p, s);
        lines[i++] = p;
    }

    writelines(lines, i, i - n);
}

void writelines(char* lineptr[], int nlines, int start_index){
    for(int i = 0; i < nlines; i++){
        if(i < start_index)
            continue;
        printf("%s\n", lineptr[i]);
    }
}
