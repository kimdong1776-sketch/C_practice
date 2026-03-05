/******************************************************
*	Lab	04.	반복
*	- File:	lab04_03.c
*	- ID:	2025003170	
*	- Name:	김  동후
******************************************************/

#include <stdio.h>

int main(){
    int num, i=0, result = 0;
    double result_average = 0;
    
    do{
        printf("정수를 입력하세요: ");
        scanf("%d", &num);
        result += num;
        i++;
    }while(num > 0);
    if(i == 1){
        printf("입력한 양의 정수가 없습니다.");
        return 0;
    }
    result_average = (double)result / ((double)i-1);
    printf("합계: %d\n평균: %.1f", result, result_average);
}