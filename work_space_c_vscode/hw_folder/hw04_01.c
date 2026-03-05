/******************************************************
*	- File:	hw04_01.c
*	- ID:	2025003170	
*	- Name:	김  동후
******************************************************/

#include<stdio.h>
#define max 6
int main(){
    for(int i = 1 ; i <= max ; i++){
        for(int j = 1 ; j <= max ; j++){
            printf("(%d,%d) = %2d: ",i, j, i+j);
            if((i+j) % 2 == 0){
                printf("Even\n");
            }
            else{
                printf("Odd\n");
            }
        }
    }
    return 0;
    

}