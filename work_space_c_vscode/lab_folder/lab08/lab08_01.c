/******************************************************
*	Lab	08.	포인터와 배열
*	- File:	lab08_01.c
*	- ID:	2025003170	
*	- Name:	김  동후
******************************************************/
#include<stdio.h>

int sum_array(int *array, int size);
int main(){ 
    int data[] = {10, 20, 30, 40, 50, 60,	70,	80,	90};
    printf("배열의 합계: %d",sum_array(data, 9));
 
}

int sum_array(int *array, int size){
    int sum = 0;
    for(int i = 0 ; i < size; i++){
        printf("%d ", *(array+i));
        sum += *(array+i);
    }
    printf("\n");
    return sum;

}