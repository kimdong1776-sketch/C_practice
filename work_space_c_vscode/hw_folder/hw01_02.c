/******************************************************
*	- File:	hw01_02.c
*	- ID:	2025003170	
*	- Name:	김  동후
******************************************************/

#include<stdio.h>
#define EXCHANGE_RATE 1330.0

int main(){
    int won;
    printf("Type Korean money(won): ");
    scanf("%d", &won);
    printf("%d won => %.2f dollar", won, won*(1/EXCHANGE_RATE));

    return 0;

}