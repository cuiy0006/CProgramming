#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "../../util/stream_op.h"

#define MAXWORD 100
#define BUFSIZE 100

static char buf[BUFSIZE];
static char bufp = 0;

struct key
{
    const char* word;
    int count;
};
struct key keytab[] = {
    "auto", 0,
    "break", 0,
    "case", 0,
    "char", 0,
    "const", 0,
    "continue", 0,
    "default", 0,
    "unsigned", 0,
    "void", 0,
    "volatile", 0,
    "while", 0
};

#define NKEYS (sizeof keytab / sizeof(struct key))

static FILE* files[100];
static int idx = 0;
static int size;

int getword(char*, int);
int binsearch(char*, struct key*, int);
int getch(void);
void ungetch(int c);

// test with
// ./C7/7-7/key_word_count_from_file ../test/resources/code0 ../test/resources/code1

main(int argc, char* argv[]){
    int n;
    char word[MAXWORD];

    int i = 0;
    while(--argc > 0){
        files[i] = fopen(argv[i + 1], "r");
        if(files[i] == NULL){
            printf("cannot open file %s\n", argv[i + 1]);
            exit(1);
        }
        ++i;
    }
    size = i;

    while(getword(word, MAXWORD) != EOF)
        if(isalpha(word[0]))
            if((n = binsearch(word, keytab, NKEYS)) >= 0)
                keytab[n].count++;
    for(n = 0; n < NKEYS; ++n)
        if(keytab[n].count > 0)
            printf("%4d %s\n", keytab[n].count, keytab[n].word);
    return 0;
}

int binsearch(char* word, struct key* tab, int size){
    int left = 0;
    int right = size - 1;
    int tmp, mid;
    while(left <= right){
        mid = (left + right) / 2;
        if((tmp = strcmp(word, tab[mid].word)) > 0)
            left = mid + 1;
        else if(tmp < 0)
            right = mid - 1;
        else
            return mid;
    }
    return -1;
}


int getword(char* word, int lim){
    int c;
    char* w = word;

    while(isspace(c = getch()))
        ;

    if(c != EOF)
        *w++ = c;

    if(!isalpha(c)){
        *w = '\0';
        return c;
    }

    for(; --lim > 0; w++)
        if(!isalnum(*w = getch())){
            ungetch(*w);
            break;
        }

    *w = '\0';
    return word[0];
}


int getch(void){
    if(bufp > 0)
        return buf[--bufp];

    if(size == 0)
        return getchar();
    else{
        char c = EOF;
        while(idx < size && (c = getc(files[idx])) == EOF)
            ++idx;
        return c;
    }
}

void ungetch(int c){
    if(bufp >= BUFSIZE){
        printf("ungetch: too many characters\n");
    } else {
        buf[bufp++] = c;
    }
}