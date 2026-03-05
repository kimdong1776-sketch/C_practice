/******************************************************
*	Lab	03.	연산자
*	- File:	lab03_01.c
*	- ID:	2025003170	
*	- Name:	김  동후
******************************************************/
#include <stdio.h>

int main(){
    
    int num;
    printf("100보다 작은 정수 입력: ");
    scanf("%d",&num);

    int result_10 = num / 10;
    printf("십의 자리 수: %d\n", result_10);

    int result_1 = num % 10;
    printf("일의 자리 수: %d",result_1);

    return 0;
} 