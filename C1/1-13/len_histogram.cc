#include <stdio.h>
#include <string.h>

int main(){
    int idx = 0;
    int lengths[100]; // = {0}
    memset(lengths, 0, sizeof(lengths));
    char c;
    int maxlen = 0;

    while((c = getchar()) != EOF){
        if(c == ' ' || c == '\t' || c == '\n'){
            if(lengths[idx] == 0)
                continue;
            maxlen = maxlen > lengths[idx]? maxlen: lengths[idx];
            ++idx;
        } else {
            ++lengths[idx];
        }
    }

    for(int i = 0; i < idx; ++i){
        printf("%3d ", i);
        for(int j = 0; j < lengths[i]; ++j){
            putchar('*');
        }
        printf("\n");
    }

}