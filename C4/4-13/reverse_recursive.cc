#include "reverse_recursive.h"
#include <string.h>

void helper(char s[], int i, int j){
    if(i >= j){
        return;
    }
    int tmp = s[i];
    s[i] = s[j];
    s[j] = tmp;
    helper(s, i + 1, j - 1);
}

void reverse_recursive(char s[]){
    helper(s, 0, strlen(s) - 1);
}