#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>
#include "../../util/stream_op.h"

#define MAX_NODES 1000
#define MAXWORD 100

struct tnode{
    char* word;
    int freq = 0;
    struct tnode* left;
    struct tnode* right;
};

struct tnode* nodes[MAX_NODES];
int idx = 0;

char* strdup(char* s);
struct tnode* talloc(void);
struct tnode* addtree(struct tnode* p, char* w);
int getword(char* word, int lim);
void qsort(void* lineptr[], int left, int right, int (*comp)(void*, void*));
int nodecmp(struct tnode*, struct tnode*);

main(int argc, char *argv[]){
    struct tnode* root;
    char word[MAXWORD];
    while(getword(word, MAXWORD) != EOF){
        if(word[0] == '\0')
            continue;
        
        root = addtree(root, word);
    }
    qsort((void**)nodes, 0, idx - 1, (int(*)(void*, void*))nodecmp);
    for(int i = idx - 1; i >= 0; --i){
        printf("%s %d\n", nodes[i]->word, nodes[i]->freq);
    }
}


struct tnode* addtree(struct tnode* p, char* w){
    int cond;
    
    if(p == NULL){
        p = talloc();
        p->word = strdup(w);
        p->freq++;
        p->left = p->right = NULL;
        nodes[idx++] = p;
    } else if((cond = strcmp(w, p->word)) == 0){
        p->freq++;
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

void qsort(void* v[], int left, int right, int (*comp)(void*, void*)){
    int i, last;
    void swap(void *v[], int i, int j);

    if(left >= right)
        return;
    swap(v, left, (left + right) / 2);
    last = left;
    for(i = left + 1; i <= right; ++i){
        if((*comp)(v[i], v[left]) < 0)
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

int nodecmp(struct tnode* node1, struct tnode* node2){
    if(node1->freq > node2->freq)
        return 1;
    else if(node1->freq < node2->freq)
        return -1;
    else
        return 0;
}