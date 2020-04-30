#include <stdio.h>

void filecopy(FILE* in, FILE* out);

// test with
// C7/7-8/print_pages ../test/resources/code0 ../test/resources/code1 ../test/resources/filea0

main(int argc, char* argv[]){
    int pageidx = 1;
    while(--argc > 0){
        printf("-------------------------------------------------------\n");
        printf("[Title] %s\n", argv[pageidx]);
        printf("[Page index] %d\n", pageidx);
        FILE* fp = fopen(argv[pageidx], "r");
        if(fp == NULL)
            printf("cannot open file %s\n", argv[pageidx]);
        else {
            filecopy(fp, stdout);
            printf("\n");
            fclose(fp);
        }
        ++pageidx;
    }
    return 0;
}


void filecopy(FILE* in, FILE* out){
    int c;
    while((c = getc(in)) != EOF){
        putc(c, out);
    }
}