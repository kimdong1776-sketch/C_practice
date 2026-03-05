/******************************************************
*	- File:	hw02_02.c
*	- ID:	2025003170	
*	- Name:	김  동후
******************************************************/

#include<stdio.h>

int main(){

   int a,b,c,median;
   printf("Input three number: ");
   scanf("%d %d %d", &a, &b ,&c);
    if ((b <= a && a <= c) || (c <= a && a <= b)) {
        median = a;
    }
    else if ((a <= b && b <= c) || (c <= b && b <= a)) {
        median = b;
    }
    else {
        median = c;
    }
   printf("Median number: %d", median);
   return 0;

}