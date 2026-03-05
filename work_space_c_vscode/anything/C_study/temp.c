#include <stdio.h>

int main (){
    int num1, num2;

    printf("정수 one:");
    scanf("%d", &num2); //10
    
    printf("정수 two:");
    scanf("%d", &num1); //20

    printf("%d + %d = %d", num1, num2, num1 + num2);

    return 0;
}