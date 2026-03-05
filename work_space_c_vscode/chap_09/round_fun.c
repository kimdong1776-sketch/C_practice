#include <stdio.h>
#include <math.h>

int main(){

    double a = 2.3;
    double b = 2.7;
    double c = -2.5;

    printf("round(%.2f) = %.2f\n", a, round(a));
    printf("round(%.2f) = %.2f\n", b, round(b));
    printf("round(%.2f) = %.2f\n", c, round(c));

    double pi = 3.141592653589;
    
    printf("round(pi*100)/100 = %.2f\n", round(pi*100)/100);
    printf("round(pi*100)/100 = %.3f\n", round(pi*1000)/1000);
    return 0;
    
}
/*
안녕하세요 





*/