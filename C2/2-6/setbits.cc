#include "setbits.h"

unsigned setbits(unsigned x, int p, int n, unsigned y){
    unsigned tmp = (~(~0 << n)) << p;
    y = (y << p) & tmp;
    x = x & (~tmp);
    return x | y;
}