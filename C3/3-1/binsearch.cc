#include "binsearch.h"

int binsearch(int x, int v[], int n){
    if(x < v[0] || x > v[n - 1]){
        return -1;
    }

    int left = 0;
    int right = n;
    while(left < right){
        int mid = (left + right) / 2;
        if(v[mid] >= x){
            right = mid;
        } else {
            left = mid + 1;
        }
    }

    if(v[left] != x){
        return -1;
    }
    return left;
}