/******************************************************
*	Lab	04.	반복
*	- File:	lab04_02.c
*	- ID:	2025003170	
*	- Name:	김  동후
******************************************************/

#include <stdio.h>

int main(){
    int i = 0;
    double rate = 0.03, money = 1000;
    while(money < 1000 * 2){
        money = money + (money * rate);
        i++;
        printf("%d year: %.2f\n", i, money);
    }
    printf("After %d years, %.2f",i,money);
    return 0;
}