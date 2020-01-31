#include <stdio.h>
int getfloat(double *pn);

main(){
    double next;
    while(true){
        int ret = getfloat(&next);
        if(ret == -1){
            printf("invalid input!\n");
            break;
        }
        if(ret != 0)
            printf("%f\n", next);
    }
}