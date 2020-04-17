#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include "../../util/stream_op.h"

#define PREFIX_LENGTH 6
#define MAX_WORDS 20
#define MAXWORD 100

struct tnode{
    char* words[MAX_WORDS];
    char* prefix;
    struct tnode* left;
    struct tnode* right;
    int idx;
};

char* strdup(char* s);
struct tnode* talloc(void);
struct tnode* addtree(struct tnode* p, char* w, char* prefix);
int getword(char* word, int lim);
void treeprint(struct tnode* p);

main(int argc, char *argv[]){
    int prefix_len = PREFIX_LENGTH;
    if(argc == 2){
        prefix_len = atoi(argv[1]);
    }

    struct tnode* root;
    char word[MAXWORD];
    while(getword(word, MAXWORD) != EOF){
        if(word[0] == '\0')
            continue;
        
        char prefix[prefix_len];
        strncpy(prefix, word, prefix_len);
        root = addtree(root, word, prefix);
    }
    treeprint(root);
}

char* strdup(char* s){
    char* p;
    p = (char*)malloc(strlen(s) + 1);
    if(p != NULL)
        strcpy(p, s);
    return p;
}

struct tnode* talloc(void){
    return (struct tnode*)malloc(sizeof(struct tnode));
}

struct tnode* addtree(struct tnode* p, char* w, char* prefix){
    int cond;
    
    if(p == NULL){
        p = talloc();
        p->idx = 0;
        p->prefix = strdup(prefix);
        p->words[p->idx++] = strdup(w);
        p->left = p->right = NULL;
    } else if((cond = strcmp(prefix, p->prefix)) == 0){
        p->words[p->idx++] = strdup(w);
    } else if(cond < 0){
        p->left = addtree(p->left, w, prefix);
    } else {
        p->right = addtree(p->right, w, prefix);
    }
    return p;
}

int getword(char* word, int lim){
    int c;

    char* w = word;
    while(isspace(c = getch()) || c == '\t' || c == '\n')
        ;

    if(c == EOF)
        return EOF;
    
    if(isalpha(c) || c == '_'){
        *w++ = c;
        --lim;
        for(; --lim > 0; w++)
            if(!isalnum(*w = getch()) && *w != '_'){
                ungetch(*w);
                break;
        }
    }
    
    *w = '\0';
    return word[0];
}

// if alphabeticl order is needed for printing words array, then use qsort here.
void treeprint(struct tnode* p){
    if(p != NULL){
        treeprint(p->left);
        for(int i = 0; i < p->idx; ++i){
            printf("%s\n", p->words[i]);
        }
        treeprint(p->right);
    }
}