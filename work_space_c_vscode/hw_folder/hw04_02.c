/******************************************************
*	- File:	hw04_02.c
*	- ID:	2025003170	
*	- Name:	김  동후
******************************************************/

#include<stdio.h>

int main(){
    int num;
    
    while(1){
        printf("출력할 최대 숫자 입력: ");
        scanf("%d", &num);


        if((num < 1)||(num > 10)){
            printf("1~10 사이의 숫자를 다시 입력하세요.\n");
            continue;
        }

        for(int i = 1; i <= num ;i++){
            for(int j = 1; j <= i ; j++){
                printf("%d ", j);
            }
            printf("\n");
        }
        for(int i = num-1; i >= 1 ; i--){
            for(int j = 1; j <= i ; j++){
                printf("%d ", j);
            }
            printf("\n");
        }
        return 0;
    }   

}