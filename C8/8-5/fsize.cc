#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <time.h>

// read(dp->fd, (char*) &dirbuf, sizeof(dirbuf)) == sizeof(dirbuf) does not work on Ubuntu,
// https://stackoverflow.com/questions/17618472/using-read-system-call-on-a-directory
// so use standard lib instead
#include <dirent.h>


void fsize(const char*);

main(int argc, char** argv){
    printf("%8s %8s %10s %10s %40s %40s %40s %8s %s\n", "mode", "nlink", "owner", "group", "last accessed", "last modified", "inode last changed", "size", "path");
    if(argc == 1)
        fsize(".");
    else
        while(--argc > 0)
            fsize(*++argv);
    return 0;
}

void dirwalk(const char*, void (*fcn)(const char*));

void fsize(const char* name){
    struct stat stbuf;

    if(stat(name, &stbuf) == -1){
        fprintf(stderr, "fsize: can't access %s\n", name);
        return;
    }

    if((stbuf.st_mode & S_IFMT) == S_IFDIR)
        dirwalk(name, fsize);

    time_t rawtime;
    struct tm *info;
    char* atime;
    char* mtime;
    char* ctime;

    rawtime = stbuf.st_atim.tv_sec;
    info = localtime(&rawtime);
    atime = asctime(info);
    atime[strlen(atime) - 1] = '\0';

    rawtime = stbuf.st_mtim.tv_sec;
    info = localtime(&rawtime);
    mtime = asctime(info);
    mtime[strlen(mtime) - 1] = '\0';

    rawtime = stbuf.st_ctim.tv_sec;
    info = localtime(&rawtime);
    ctime = asctime(info);
    ctime[strlen(ctime) - 1] = '\0';
    
    printf("%8o %8ld %10d %10d %40s %40s %40s %8ld %s\n", stbuf.st_mode, stbuf.st_nlink, stbuf.st_uid, stbuf.st_gid, atime, mtime, ctime, stbuf.st_size, name);
}

#define MAX_PATH 1024

void dirwalk(const char* dir, void (*fcn)(const char*)){
    char name[MAX_PATH];
    dirent* dp;
    DIR* dfd;

    if((dfd = opendir(dir)) == NULL){
        fprintf(stderr, "dirwalk: can't open %s\n", dir);
        return;
    }

    while((dp = readdir(dfd)) != NULL){
        if(strcmp(dp->d_name, ".") == 0 || strcmp(dp->d_name, "..") == 0)
            continue;
        if(strlen(dir) + strlen(dp->d_name) + 2 > sizeof(name))
            fprintf(stderr, "dirwalk: name %s/%s too long\n", dir, dp->d_name);
        else {
            sprintf(name, "%s/%s", dir, dp->d_name);
            (*fcn)(name);
        }
    }

}