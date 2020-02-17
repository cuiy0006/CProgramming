#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "../../util/util.h"
#include "../../util/memory_op.h"
#define MAXLINES 5000
#define MAXLEN 1000
char *lineptr[MAXLINES];

int readlines(char* lineptr[], int maxlines);
void writelines(char* lineptr[], int nlines);
void qsort(void* lineptr[], int left, int right, int (*comp)(void*, void*));
int numcmp(char*, char*);
int stringcmp(char*, char*);

static char option = 0b00000000;
#define NUMERIC 0b00000001
#define REVERSE 0b00000010
#define FOLD 0b00000100
#define DICTIONARY 0b00001000

main(int argc, char *argv[]){
    int nlines;

    while(--argc > 0 && (*++argv)[0] == '-'){
        char* arg = *argv + 1;
        while(*arg != '\0'){
            if(*arg == 'n'){
                option |= NUMERIC;
            } else if(*arg == 'r'){
                option |= REVERSE;
            } else if(*arg == 'f'){
                option |= FOLD;
            } else if(*arg == 'd'){
                option |= DICTIONARY;
            }
            ++arg;
        }
    }

    if((nlines = readlines(lineptr, MAXLINES)) >= 0){
        if(option & NUMERIC)
            qsort((void **)lineptr, 0, nlines-1, (int (*)(void *,void *))numcmp);
        else
            qsort((void **)lineptr, 0, nlines-1, (int (*)(void *,void *))stringcmp);
        writelines(lineptr, nlines);
        return 0;
    } else {
        printf("input too big to sort\n");
        return 1;
    }
}

void qsort(void* v[], int left, int right, int (*comp)(void*, void*)){
    int reverse = option & REVERSE? -1: 1;
    int i, last;
    void swap(void *v[], int i, int j);

    if(left >= right)
        return;
    swap(v, left, (left + right) / 2);
    last = left;
    for(i = left + 1; i <= right; ++i){
        if(reverse * (*comp)(v[i], v[left]) < 0)
            swap(v, ++last, i);
    }
    swap(v, left, last);
    qsort(v, left, last - 1, comp);
    qsort(v, last + 1, right, comp);
}

void swap(void* v[], int i, int j){
    void* temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

int numcmp(char* s1, char* s2){
    double v1 = atof(s1);
    double v2 = atof(s2);
    if(v1 < v2)
        return -1;
    else if(v1 > v2)
        return 1;
    else
        return 0;
}

int stringcmp(char* s1, char* s2){
    while(*s1 != '\0' || *s2 != '\0'){
        if(option & DICTIONARY){
            while(*s1 != '\0' && !isalnum(*s1) && *s1 != ' '){
                ++s1;
            }
            while(*s2 != '\0' && !isalnum(*s2) && *s2 != ' '){
                ++s2;
            }
            if(*s1 == '\0' && *s2 == '\0')
                return 0;
        }
        char c1 = *s1++;
        char c2 = *s2++;
        if(option & FOLD){
            c1 = isalpha(c1)? tolower(c1): c1;
            c2 = isalpha(c2)? tolower(c2): c2;
        } 
        if(c1 == '\0')
            return -1;
        if(c2 == '\0')
            return 1;
        if(c1 != c2)
            return c1 - c2;
    }
    return 0;
}

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

void writelines(char* lineptr[], int nlines){
    while(nlines-- > 0){
        printf("%s\n", *lineptr++);
    }
}