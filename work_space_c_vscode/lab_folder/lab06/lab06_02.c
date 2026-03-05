/******************************************************
*	Lab	06.	함수
*	- File:	lab06_02.c
*	- ID:	2025003170	
*	- Name:	김  동후
******************************************************/
#include<stdio.h>

int getsum(int n);

int main(){ 
    int num;
    
    while(1){
        printf("Input a number: ");
        scanf("%d", &num);
        if (num <= 0){
            printf("Try Again (%d <= 0)", num);
            continue;
        }

        printf("Sum from 1 to %d = %d",num,getsum(num));
        break;
        
    }
    
}

int getsum(int n){
    int sum=0;
    for(int i = 1 ; i <= n; i++){
        printf("%d = %d + %d\n", sum+i, sum, i);
        sum += i;
    }
    return sum;
}