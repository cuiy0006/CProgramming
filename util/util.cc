#include "util.h"
#include <iostream>
#include <stdio.h>

void reverse(char s[], int start, int end){
    while(start < end){
        int tmp = s[start];
        s[start] = s[end];
        s[end] = tmp;
        ++start;
        --end;
    }
}

void pad_left(char s[], int length, int width, char c){
    if(width <= length){
        return;
    }
    s[width] = '\0';
    int i = length - 1;
    int j = width - 1;
    while(i >= 0){
        s[j--] = s[i--];
    }

    while(j >= 0){
        s[j--] = c;
    }
}

void printStr(char s[]){
    int i = 0;
    while(s[i] != '\0'){
        putchar(s[i++]);
    }
    printf("\n-----------------------------------\n");
}

int atoi(char s[], int start){
    int i = start;
    int sign = 1;
    if(s[i] == '+'){
        ++i;
    } else if(s[i] == '-'){
        sign = -1;
        ++i;
    }
    int res = 0;
    while(s[i] != '\0'){
        res = res * 10 + (s[i] - '0');
        ++i;
    }
    return sign * res;
}

int getline(char s[], int lim){
    int i = 0;
    char c;
    while((c = getchar()) != EOF && c != '\n' && i < lim - 1){
        s[i++] = c;
    }

    if(i < lim - 1 && c == '\n'){
        s[i++] = c;
    }

    s[i] = '\0';
    return i;
}

void printline(char s[], int lim){
    for(int i = 0; i < lim; ++i){
        if(s[i] == '\0'){
            break;
        }
        putchar(s[i]);
    }
}