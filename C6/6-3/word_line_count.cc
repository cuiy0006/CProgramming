#include <string.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include "../../util/stream_op.h"

#define MAX_LINES 30
#define MAXWORD 100
#define IGNORE_SIZE 6

const char* ignores[IGNORE_SIZE] = {
    "a",
    "an",
    "and",
    "that",
    "the",
    "this"
};

struct tnode{
    char* word;
    int lines[MAX_LINES];
    int idx = 0;
    struct tnode* left;
    struct tnode* right;
};

int binsearch(char*, const char*[], int);
char* strdup(char* s);
struct tnode* talloc(void);
struct tnode* addtree(struct tnode* p, char* w);
int getword(char* word, int lim);
void treeprint(struct tnode* p);
int line = 1;

main(int argc, char *argv[]){
    struct tnode* root;
    char word[MAXWORD];
    while(getword(word, MAXWORD) != EOF){
        if(word[0] == '\0' || binsearch(word, ignores, IGNORE_SIZE) != -1)
            continue;
        
        root = addtree(root, word);
    }
    treeprint(root);
}

struct tnode* addtree(struct tnode* p, char* w){
    int cond;
    
    if(p == NULL){
        p = talloc();
        p->word = strdup(w);
        p->lines[p->idx++] = line;
        p->left = p->right = NULL;
    } else if((cond = strcmp(w, p->word)) == 0){
        // if do not need duplicated line NO, add condition here
        p->lines[p->idx++] = line;
    } else if(cond < 0){
        p->left = addtree(p->left, w);
    } else {
        p->right = addtree(p->right, w);
    }
    return p;
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


int binsearch(char* word, const char* ignores[], int size){
    int left = 0;
    int right = size - 1;
    int tmp, mid;
    while(left <= right){
        mid = (left + right) / 2;
        if((tmp = strcmp(word, ignores[mid])) > 0)
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
    while(isspace(c = getch()) || c == '\t' || c == '\n'){
        if(c == '\n')
            line++;
    }

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

void treeprint(struct tnode* p){
    if(p != NULL){
        treeprint(p->left);
        printf("%s: ", p->word);
        for(int i = 0; i < p->idx; ++i){
            printf("%d ", p->lines[i]);
        }
        printf("\n");
        treeprint(p->right);
    }
}