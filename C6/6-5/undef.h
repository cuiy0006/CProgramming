struct nlist {
    struct nlist* next;
    char* name;
    char* defn;
};

#define HASHSIZE 101
static struct nlist* hashtab[HASHSIZE];
unsigned hash(char* s);
struct nlist* lookup(char* s);
char* strdup(char* s);
struct nlist* install(char*, char*);
int undef(char* name);