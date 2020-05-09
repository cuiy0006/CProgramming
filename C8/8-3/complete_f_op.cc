#include "complete_f_op.h"
#include <fcntl.h>
#include <stdlib.h>
#include "unistd.h"
#define PERMS 0666

FILE _iob[OPEN_MAX] = {
    {0, (char*) 0, (char*) 0, _READ, 0},
    {0, (char*) 0, (char*) 0, _WRITE, 1},
    {0, (char*) 0, (char*) 0, _WRITE & _UNBUF, 2}
};

FILE* fopen(const char* name, const char* mode){
    int fd;
    FILE *fp;

    if(*mode != 'r' && *mode != 'w' && *mode != 'a')
        return NULL;
    for(fp = _iob; fp < _iob + OPEN_MAX; fp++)
        if((fp->flag & (_READ | _WRITE)) == 0)
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
    fp->flag = (*mode == 'r') ? _READ : _WRITE;
    return fp;
}

int _fillbuf(FILE* fp){
    int bufsize;

    if((fp->flag&(_READ|_EOF|_ERR)) != _READ)
        return EOF;
    
    bufsize = (fp->flag & _UNBUF) ? 1 : BUFSIZE;
    if(fp->base == NULL)
        if((fp->base = (char*) malloc(bufsize)) == NULL)
            return EOF;
    fp->ptr = fp->base;
    fp->cnt = read(fp->fd, fp->ptr, bufsize);
    if(--fp->cnt < 0){
        if(fp->cnt == -1)
            fp->flag |= _EOF;
        else
            fp->flag |= _ERR;
        fp->cnt = 0;
        return EOF;
    }
    return (unsigned char) *fp->ptr++;
}

int _flushbuf(int x, FILE* fp){
    if((fp->flag&(_WRITE|_ERR)) != _WRITE)
        return EOF;

    int bufsize;
    bufsize = (fp->flag & _UNBUF) ? 1 : BUFSIZE;

    if(fp->base == NULL){
        if((fp->base = (char*) malloc(bufsize)) == NULL)
            return EOF;
        fp->cnt = bufsize;
        fp->ptr = fp->base;
    } else {
        if(fp->cnt < -1){
            fp->flag |= _ERR;
            return EOF;
        }

        ++fp->cnt;
        if(fflush(fp) == EOF)
            return EOF;
    }
    *fp->ptr++ = x;
    --fp->cnt;
    return 1;
}

int fclose(FILE* fp){
    free(fp->base);
    fp->base = NULL;
    fp->ptr = NULL;
    fp->cnt = 0;
    fp->flag = 0;
    return close(fp->fd);
}

int fflush(FILE* fp){
    if(fp->base == NULL){
        fp->flag |= _ERR;
        return EOF;
    }

    if((fp->flag&(_WRITE|_ERR)) != _WRITE)
        return EOF;

    int bufsize = (fp->flag & _UNBUF) ? 1 : BUFSIZE;
    int to_write = bufsize - fp->cnt;

    if(write(fp->fd, fp->base, to_write) != to_write){
        fp->flag |= _ERR;
        return EOF;
    }

    fp->cnt = bufsize;
    fp->ptr = fp->base;
    return 1;
}