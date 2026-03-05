#include<stdio.h>

int main(){
    int num = 11, num2 = 111;
    int a = printf("aa%d", num); 
    int b = printf("aa%d", num2);
    printf("\n\n");
    printf("%d, %d", a, b);
    return 0;
}