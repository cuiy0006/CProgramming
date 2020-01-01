#include <reverseline.h>

void reverseline(int left, int right, char c[]){
    while(left < right){
        char tmp = c[left];
        c[left] = c[right];
        c[right] = tmp;
        ++left;
        --right;
    }
}