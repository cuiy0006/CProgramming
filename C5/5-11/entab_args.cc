#include <stdio.h>
#include <stdlib.h>
#define MAXLINE 1000

void printline(char s[], int lim);
int getline(char s[], int lim, int tabs[], int ltb);

main(int argc, char *argv[]){
    int tabs[100];
    int tab_idx = 0;
    while(--argc > 0){
        tabs[tab_idx++] = atoi(*++argv);
    }
    if(argc != 0){
        printf("Usage: entab_args i j k ...\n");
        return 0;    
    }
    char s[MAXLINE];
    int len;
    while((len = getline(s, MAXLINE, tabs, tab_idx)) != 0){
        printf("%d: ", len);
        printline(s, MAXLINE);
        putchar('\n');
    }
}

void printline(char s[], int lim){
    for(int i = 0; i < lim; ++i){
        if(s[i] == '\0'){
            break;
        }
        putchar(s[i]);
    }
}

#define TABSIZE 7

int getline(char s[], int lim, int tabs[], int ltb){
    int i = 0;
    int offset = 0;
    char c;
    int tab_idx = 0;
    while((c = getchar()) != EOF && c != '\n' && i < lim - 1){
        int tabsize = tab_idx < ltb? tabs[tab_idx]: TABSIZE;
        if(c == '\t' || (offset == tabsize - 1 && c == ' ')){
            int j = i - 1;
            while(j >= 0 && j >= i - tabsize + 1 && s[j] == ' '){
                --j;
            }
            s[j + 1] = '|';
            if(j == i - 1 && c == ' '){
                s[j + 1] = ' ';
            }
            i = j + 2;
            offset = 0;
            ++tab_idx;
            continue;
        }
        s[i] = c;
        ++i;
        ++offset;
        if(offset == tabsize){
            offset = 0;
            ++tab_idx;
        }
    }

    if(i < lim - 1 && c == '\n'){
        s[i++] = c;
    }

    s[i] = '\0';
    return i;
}