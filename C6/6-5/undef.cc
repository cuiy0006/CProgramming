#include <stdlib.h>
#include <string.h>
#include "undef.h"

struct nlist* install(char* name, char* defn){
    struct nlist* np;
    unsigned hashval;

    if((np = lookup(name)) == NULL){
        np = (struct nlist*)malloc(sizeof(struct nlist));
        if(np == NULL || (np->name = strdup(name)) == NULL)
            return NULL;
        
        hashval = hash(name);
        np->next = hashtab[hashval];
        hashtab[hashval] = np;
    } else
        free((void*)np->defn);
    if((np->defn = strdup(defn)) == NULL)
        return NULL;
    return np;
}

int undef(char* name){
    unsigned hashval;
    hashval = hash(name);
    struct nlist* np = hashtab[hashval];
    struct nlist* toremove;
    if(np == NULL)
        return -1;
    else if(strcmp(name, np->name) == 0){
        hashtab[hashval] = np->next;
        toremove = np;
    } else {
        while(np->next != NULL && strcmp(name, np->next->name) != 0)
            np = np->next;
        if(np->next == NULL)
            return -1;
        toremove = np->next;
        np->next = np->next->next;
    }

    free((void*)toremove->name);
    free((void*)toremove->defn);
    free((void*)toremove);
    return 0;
}

struct nlist* lookup(char* s){
    struct nlist* np;

    for(np = hashtab[hash(s)]; np != NULL; np = np->next){
        if(strcmp(s, np->name) == 0)
            return np;
    }
    return NULL;
}

unsigned hash(char* s){
    unsigned hashval;
    
    for(hashval = 0; *s != '\0'; s++)
        hashval = *s + 31 * hashval;
    return hashval % HASHSIZE;
}

char* strdup(char* s){
    char* p = (char*)malloc(strlen(s) + 1);
    if(p != NULL)
        strcpy(p, s);
    return p;
}
