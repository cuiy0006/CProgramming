#include <string.h>
#include <stdio.h>
#include "readlines.h"
#include "../../util/util.h"
#define MAXLINES 5000
#define MAXLEN 1000

void writelines(char* lineptr[], int nlines){
    while(nlines-- > 0){
        printf("%s\n", *lineptr++);
    }
}

int main(int argc, char *argv[]){
    if(argc == 2 && strcmp(argv[1], "-new") == 0){
        printf("using initialized lineptr\n");
        char* lineptr[MAXLINES];
        char longline[MAXLEN * MAXLINES];
        int nlines = readlines_cmp(lineptr, longline, MAXLINES);
        writelines(lineptr, nlines);
    } else {
        printf("using non-initialized lineptr\n");
        char* lineptr[MAXLINES];
        int nlines = readlines(lineptr, MAXLINES);
        writelines(lineptr, nlines);
    }
}