#include "bitcount.h"
#include "stdio.h"

int bitcount(unsigned x){
    int cnt = 0;
    while(x != 0){
        x &= (x - 1);
        ++cnt;
    }
    return cnt;
}

int bitcount_old(unsigned x){
    int b;
    for(b = 0; x != 0; x >>= 1){
        if(x & 1){
            b++;
        }
    }
    return b;
}