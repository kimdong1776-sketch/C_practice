/******************************************************
*	Lab	04.	반복
*	- File:	lab04_01.c
*	- ID:	2025003170	
*	- Name:	김  동후
******************************************************/

#include <stdio.h>

int main(){
    int num = 0, result = 0;
    printf("1~100 사이의 정수 입력: ");
    scanf("%d", &num);
    for(int count = 3;count <= num; count += 3){
        printf("%d", count);

        if((count != num)&&((num - count) > 2)){
            printf(" + ");
        }
        result += count;
    }
    printf(" = %d", result);
}