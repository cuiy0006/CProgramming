#include <stdio.h>
#include <f_to_c.h>

int main(){
    float fahr, celsius;
    int lower, upper, step;
    lower = 0;
    upper = 300;
    step = 20;

    printf("fahr celsius\n");
    for(fahr = lower; fahr <= upper; fahr += step){
        celsius = f_to_c(fahr);
        printf("%3.0f  %5.1f\n", fahr, celsius);
    }
}