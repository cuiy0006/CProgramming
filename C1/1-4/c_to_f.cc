#include <stdio.h>

int main(){
    float fahr, celsius;
    int lower, upper, step;
    lower = -20;
    upper = 160;
    step = 10;

    for(celsius = lower; celsius <= upper; celsius += step){
        fahr = celsius * 9 / 5 + 32;
        printf("%3.0f  %5.1f\n", celsius, fahr);
    }
}