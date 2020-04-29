#include "diff_file.h"
#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

bool diff_file(const char* file1_path, const char* file2_path, char* diff_line1, char* diff_line2){
    FILE* fp1;
    FILE* fp2;
    if((fp1 = fopen(file1_path, "r")) == NULL || (fp2 = fopen(file2_path, "r")) == NULL){
        fprintf(stderr, "cannot open file");
        return false;
    }

    char line1[MAXLINE];
    char line2[MAXLINE];

    char* r1;
    char* r2;

    while(true){
        char* r1 = fgets(line1, MAXLINE, fp1);
        char* r2 = fgets(line2, MAXLINE, fp2);
        if(r1 == NULL && r2 == NULL)
            break;

        if(r1 == NULL){
            diff_line1[0] = '\0';
            strcpy(diff_line2, line2);
            return true;
        }

        if(r2 == NULL){
            diff_line2[0] = '\0';
            strcpy(diff_line1, line1);
            return true;
        }
        
        if(strcmp(line1, line2) != 0){
            strcpy(diff_line1, line1);
            strcpy(diff_line2, line2);
            return true;
        }
    }
    return false;
}