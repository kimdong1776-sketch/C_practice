/******************************************************
*	Lab	07.	함수
*	- File:	lab07_01.c
*	- ID:	2025003170	
*	- Name:	김  동후
******************************************************/
#include<stdio.h>

void get_sum_diff(int x, int y, int *p_sum, int *p_diff);

int main(){ 
    
    int sum = 0, diff = 0;
    int x = 0, y = 0;
    printf("Input two integers: ");
    scanf("%d %d",&x,&y);
    printf("x : %d, y: %d\n",x, y);
    get_sum_diff(x,y,&sum, &diff);

    printf("sum = %d\n", sum);
    printf("diff= %d\n", diff);

    return 0;

    
}

void get_sum_diff(int x, int y, int *p_sum, int *p_diff){

    *p_sum += x + y;
    *p_diff = (x - y);
    
}