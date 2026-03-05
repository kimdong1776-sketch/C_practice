#include<stdio.h>

int main(){
    int input =0, digit =0, divider = 100;
    printf("양의 정수[100~999] 입력 : ");
    scanf("%d", &input);
    do{
        digit = input / divider;
        input %= divider;
        printf("%3d단위 출력: %d\n",divider, digit);
        divider /= 10;
    }while(divider >= 1);
    return 0;
}