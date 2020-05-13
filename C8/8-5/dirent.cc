#include "dirent.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

#ifndef DIRSIZ
#define DIRSIZ 14
#endif

struct direct {
    ino_t d_ino;
    char d_name[DIRSIZ];
};

DIR* opendir(const char* dirname){
    int fd;
    struct stat stbuf;
    DIR* dp;
    if((fd = open(dirname, O_RDONLY, 0)) == -1
    || fstat(fd, &stbuf) == -1
    || (stbuf.st_mode & S_IFMT) != S_IFDIR
    || (dp = (DIR*) malloc(sizeof(DIR))) == NULL)
        return NULL;
    dp->fd = fd;
    return dp;
}

Dirent* readdir(DIR* dp){
    struct direct dirbuf;
    static Dirent d;

    
    int a = read(dp->fd, (char*) &dirbuf, sizeof(dirbuf));
    while(read(dp->fd, (char*) &dirbuf, sizeof(dirbuf)) == sizeof(dirbuf)){
        if(dirbuf.d_ino == 0)
            continue;
        d.ino = dirbuf.d_ino;
        strncpy(d.name, dirbuf.d_name, DIRSIZ);
        d.name[DIRSIZ] = '\0';
        return &d;
    }
    return NULL;
}

void closedir(DIR* dp){
    if(dp){
        close(dp->fd);
        free(dp);
    }
}