/******************************************************
*	Lab	03.	연산자
*	- File:	lab03_02.c
*	- ID:	2025003170	
*	- Name:	김  동후
******************************************************/
#include <stdio.h>

int main(){
    
    int num;
    printf("정수를 입력하세요: ");
    scanf("%d", &num);
    printf("입력 값: 0x%08x\n", num);
    printf("Step1. 1의 보수: 0x%x\n", ~num);
    printf("Step2. 2의 보수: 0x%x, %d", ~num + 0x1, ~num + 0x1);

    return 0;
} 
