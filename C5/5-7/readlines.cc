#include "readlines.h"
#include <string.h>
#include "../../util/util.h"
#include "../../util/memory_op.h"
#include "stdio.h"
#define MAXLEN 1000

int readlines(char *lineptr[], int maxlines){
    int len, nlines;
    char *p, line[MAXLEN];
    nlines = 0;
    while((len = getline(line, MAXLEN)) > 0){
        if(nlines >= maxlines || (p = alloc(len)) == NULL)
            return -1;
        else {
            line[len - 1] = '\0';
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    }
    return nlines;
}

int readlines_cmp(char *lineptr[], char* longline, int maxlines){
    int len, nlines;
    char *p = longline;
    char line[MAXLEN];
    nlines = 0;
    while((len = getline(line, MAXLEN)) > 0){
        if(nlines >= maxlines)
            return -1;
        else {
            line[len - 1] = '\0';
            strcpy(p, line);
            lineptr[nlines++] = p;
            p += len;
        }
    }
    return nlines;
}
