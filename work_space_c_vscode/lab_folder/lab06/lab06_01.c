/******************************************************
*	Lab	06.	함수
*	- File:	lab06_01.c
*	- ID:	2025003170	
*	- Name:	김  동후
******************************************************/
#include<stdio.h>

int evenodd(int n);
int absolute(int n);

int main(){ 
    
    char agree;
    int num;
    do{
        printf("Input an integer number: ");
        scanf("%d", &num);

        printf("%d: ", num);
        evenodd(num)==0?printf("Odd number\n"):printf("Even number\n");

        printf("absolute(%d): %d\n",num, absolute(num));

        printf("-------------------------\n");
        printf("Again? (y/n) ");

        agree = getchar();
        scanf("%c", &agree);
        
    }while(agree == 'y');
    printf("Finish");
    return 0;
}

int evenodd(int n){
    return (n % 2) == 0 ? 0 : 1;
}  

int absolute(int n){
    return n < 0 ? -1 * n : n;
}
