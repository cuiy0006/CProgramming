#include "rightrot.h"

unsigned rightrot(unsigned x, int n){
    n = n % 32;
    int tmp = ~(~0 << n);
    int cut = tmp & x;
    x = x >> n;
    return x | (cut << (32 - n));
}