#include "_fillbuf_rewrite.h"
#include <fcntl.h>
#include <stdlib.h>
#include <assert.h>
#include "unistd.h"
#define PERMS 0666

FILE _iob[OPEN_MAX] = {
    {0, (char*) 0, (char*) 0, {1, 0, 0, 0, 0}, 0},
    {0, (char*) 0, (char*) 0, {0, 1, 0, 0, 0}, 1},
    {0, (char*) 0, (char*) 0, {0, 1, 1, 0, 0}, 2}
};

FILE* fopen(const char* name, const char* mode){
    int fd;
    FILE *fp;

    if(*mode != 'r' && *mode != 'w' && *mode != 'a')
        return NULL;
    for(fp = _iob; fp < _iob + OPEN_MAX; fp++)
        if(fp->flag._READ == 0 && fp->flag._WRITE == 0)
            break;
    
    if(fp >= _iob + OPEN_MAX)
        return NULL;
    
    if(*mode == 'w')
        fd = creat(name, PERMS);
    else if(*mode == 'a'){
        if((fd = open(name, O_WRONLY, 0)) == -1)
            fd = creat(name, PERMS);
        lseek(fd, 0L, 2);
    } else
        fd = open(name, O_RDONLY, 0);
    
    if(fd == -1)
        return NULL;
    
    fp->fd = fd;
    fp->cnt = 0;
    fp->base = NULL;
    if(*mode == 'r')
        fp->flag._READ = 1;
    else
        fp->flag._WRITE = 1;
    return fp;
}

int _fillbuf(FILE* fp){
    int bufsize;

    if(fp->flag._READ == 0 || fp->flag._EOF == 1 || fp->flag._ERR == 1)
        return EOF;
    
    bufsize = (fp->flag._UNBUF == 1) ? 1 : BUFSIZE;
    if(fp->base == NULL)
        if((fp->base = (char*) malloc(bufsize)) == NULL)
            return EOF;
    fp->ptr = fp->base;
    fp->cnt = read(fp->fd, fp->ptr, bufsize);
    if(--fp->cnt < 0){
        if(fp->cnt == -1)
            fp->flag._EOF = 1;
        else
            fp->flag._ERR = 1;
        fp->cnt = 0;
        return EOF;
    }
    return (unsigned char) *fp->ptr++;
}

