#include <stdio.h>

int main(){
    float fahr, celsius;
    int lower, upper, step;
    lower = 0;
    upper = 300;
    step = 20;

    printf("fahr celsius\n");
    for(fahr = lower; fahr <= upper; fahr += step){
        celsius = (fahr - 32) * 5 / 9;
        printf("%3.0f  %5.1f\n", fahr, celsius);
    }
}