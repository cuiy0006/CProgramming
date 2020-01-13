#include "invert.h"

unsigned invert(unsigned x, int p, int n){
    unsigned tmp = (~(~0 << n)) << p;
    unsigned cut = ~(~tmp | x);
    x = ~tmp & x;
    return x | cut;
}