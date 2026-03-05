#include<stdio.h>

int main(){
    int num1= 10, num2 = 20;
    int *pnum1 = &num1 , *pnum2 = &num2;
    *pnum1 += 10;
    *pnum2 -= 10;
    
    pnum1 = &num2;
    pnum2 = &num1;

    printf("num2 : %d num1: %d", *pnum1, *pnum2);
    
}