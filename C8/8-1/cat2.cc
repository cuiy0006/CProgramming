#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

// test with
// ./C8/8-1/cat2 ../test/resources/code0 ../test/resources/code1

main(int argc, char* argv[]){
    int fd;
    void filecopy(int, int);

    if(argc == 1)
        filecopy(0, 1);
    else
        while (--argc > 0){
            if((fd = open(*++argv, O_RDONLY, 0)) > 0){
                filecopy(fd, 1);
                close(fd);
            } else {
                printf("cat: can't open %s\n", *argv);
                return 1;
            }
        }
    return 0;
}

void filecopy(int ifd, int ofd){
    char buf[BUFSIZ];
    int n;

    while((n = read(ifd, buf, BUFSIZ)) > 0)
        write(ofd, buf, n);
    
    return;
}