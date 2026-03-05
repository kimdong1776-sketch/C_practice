/******************************************************
*	Lab	05.	반복
*	- File:	lab05_01.c
*	- ID:	2025003170	
*	- Name:	김  동후
******************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    int count[6] = {0};
    int num, dice_num;

    do{
        printf("주사위를 던질 횟수를 입력하세요(10000 이상): ");
        scanf("%d", &num);
    }while(num < 10000);
    
    
    srand(time(NULL));
    
    for(int i = 0; i < num ; i++){
        dice_num = rand() % 6;
        count[dice_num]++;
    } 

    printf("Number    Frequency    Percentage(%%)\n");
    printf("-----------------------------------\n");
    for(int i = 0 ; i <= 5 ; i++){
        printf("  %d         %d            %.2f\n",i+1,count[i], ((double)count[i]/(double)num)*100);
    }
    printf("-----------------------------------\n");
    printf("Total number: %d", num);

}
