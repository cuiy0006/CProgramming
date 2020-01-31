#include <stdio.h>
int getint(int *pn);

main(){
    int next;
    while(true){
        int ret = getint(&next);
        if(ret == -1){
            printf("invalid input!\n");
            break;
        }
        if(ret != 0)
            printf("%d\n", next);
    }
}