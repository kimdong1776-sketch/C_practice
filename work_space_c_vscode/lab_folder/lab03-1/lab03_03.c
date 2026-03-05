/******************************************************
*	Lab	03.	연산자
*	- File:	lab03_03.c
*	- ID:	2025003170	
*	- Name:	김  동후
******************************************************/
#include <stdio.h>

int main(){
    
    double weight, height;
    printf("몸무게를 kg 단위로 입력: ");
    
    scanf("%lf", &weight);	
    printf("키를 meter 단위로 입력: ");
    scanf("%lf", &height);
    printf("BMI: %.2lf", weight/(height*height));

    return 0;
} 