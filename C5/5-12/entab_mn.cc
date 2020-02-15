#include <stdio.h>
#include <stdlib.h>
#define MAXLINE 1000
#define M 5
#define N 7

void printline(char s[], int lim);
int getline(char s[], int lim, int m, int n);

main(int argc, char *argv[]){
    int m = M;
    int n = N;
    ++argv;
    while(--argc > 0){
        if(**argv == '+'){
            n = atoi(*argv + 1);
            ++argv;
        } else if(**argv == '-'){
            m = atoi(*argv + 1);
            ++argv;
        } else {
            printf("Usage: entab_mn -m +n\n");
            return 0;
        }
    }

    char s[MAXLINE];
    int len;
    while((len = getline(s, MAXLINE, m, n)) != 0){
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

int getline(char s[], int lim, int m, int n){
    int i = 0;
    int offset = 0;
    char c;

    while((c = getchar()) != EOF && c != '\n' && i < lim - 1){
        if(i < m - 1){
            s[i++] = c;
            continue;
        }
        if(c == '\t' || (offset == n - 1 && c == ' ')){
            int j = i - 1;
            while(j >= i - n + 1 && s[j] == ' '){
                --j;
            }
            s[j + 1] = '|';
            if(j == i - 1){
                if(c == ' ' || (c == '\t' && offset == n - 1))
                    s[j + 1] = ' ';
            }
            i = j + 2;
            offset = 0;
            continue;
        }
        s[i] = c;
        ++i;
        ++offset;
        offset = offset % n;
    }

    if(i < lim - 1 && c == '\n'){
        s[i++] = c;
    }

    s[i] = '\0';
    return i;
}