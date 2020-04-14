#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "../../util/stream_op.h"

#define MAXWORD 100

struct key
{
    const char* word;
    int count;
};
struct key keytab[] = {
    "_Alignas", 0,
    "_Static_assert", 0,
    "_Thread_local", 0,
    "auto", 0,
    "break", 0,
    "case", 0,
    "char", 0,
    "const", 0,
    "continue", 0,
    "default", 0,
    "define", 0,
    "endif", 0,
    "unsigned", 0,
    "void", 0,
    "volatile", 0,
    "while", 0,
};

#define NKEYS (sizeof keytab / sizeof(struct key))

int getword(char*, int);
int binsearch(char*, struct key*, int);

main(){
    int n;
    char word[MAXWORD];

    while(getword(word, MAXWORD) != EOF)
        if(word[0] != '\0')
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
    int d;
    char* w = word;
    void end_with(char);
    void end_double_quote();

    while(isspace(c = getch()) || c == '\t' || c == '\n')
        ;

    if(c == EOF)
        return EOF;
    
    if(isalpha(c) || c == '_' || c == '#'){
        if(c != '#')
            *w++ = c;
        for(; --lim > 0; w++)
            if(!isalnum(*w = getch()) && *w != '_'){
                ungetch(*w);
                break;
        }
    }
    else if(c == '\'' || c == '"')
        end_with(c);
    else if(c == '/')
        if((d = getch()) == '/')
            end_with('\n');
        else if(d == '*')
            end_double_quote();
        else
            ungetch(d);
        

    *w = '\0';
    return word[0];
}

void end_with(char e){
    char c;
    while((c = getch()) != EOF){
        if(c == e)
            break;
    }
}

void end_double_quote(){
    char c;
    char d;
    while((c = getch()) != EOF){
        if(c == '*')
            if((d = getch()) == '/' || d == EOF)
                break;
            else
                ungetch(d);
    }
}