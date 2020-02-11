#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>

int main(int argc, char* argv[]){
    int nums[100];
    int* pnum = nums;
    while(--argc > 0){
        if(isdigit((*++argv)[0])){
            *pnum++ = atoi(*argv);
        } else {
            int num2 = *--pnum;
            int num1 = *--pnum;
            switch ((*argv)[0])
            {
            case '+':
                *pnum++ = num1 + num2;
                break;
            case '-':
                *pnum++ = num1 - num2;
                break;
            case '*': // input must be "*" rather than plain *
                *pnum++ = num1 * num2;
                break;
            case '/':
                *pnum++ = num1 / num2;
                break;
            default:
                break;
            }
        }
    }
    printf("%d\n", nums[0]);
}