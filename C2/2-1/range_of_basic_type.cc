#include <limits.h>
#include <stdio.h>
#include <math.h>

int main(){
    printf("Range of char: %d - %d\n", CHAR_MIN, CHAR_MAX);
    printf("Range of char: %d - %d (calculated)\n", -(int)pow(2, 7), (int)pow(2, 7) - 1);
    printf("Range of unsigned char: %d - %d\n", 0, UCHAR_MAX);
    printf("Range of unsigned char: %d - %d (calculated)\n", 0, (int)pow(2, 8) - 1);

    printf("Range of short: %d - %d\n", SHRT_MIN, SHRT_MAX);
    printf("Range of short: %d - %d (calculated)\n", -(int)pow(2, 15), (int)pow(2, 15) - 1);
    printf("Range of usigned short: %d - %d\n", 0, USHRT_MAX);
    printf("Range of usigned short: %d - %d (calculated)\n", 0, (int)pow(2, 16) - 1);

    printf("Range of int: %d - %d\n", INT_MIN, INT_MAX);
    printf("Range of int: %d - %d (calculated)\n", -(int)pow(2, 31), (int)pow(2, 31) - 1);
    printf("Range of usigned int: %u - %u\n", 0, UINT_MAX);
    printf("Range of usigned int: %u - %u (calculated)\n", 0, (uint)(pow(2, 32) - 1));

    printf("Range of long: %ld - %ld\n", LONG_MIN, LONG_MAX);
    printf("Range of long: %ld - %ld (calculated)\n", -(long)pow(2, 63), (long)pow(2, 63) - 1);
    printf("Range of usigned long: %lu - %lu\n", (unsigned long)0, ULONG_MAX);
    printf("Range of usigned long: %lu - %lu (calculated)\n", (unsigned long)0, (unsigned long)pow(2, 63) - 1 + (unsigned long)pow(2, 63));
}