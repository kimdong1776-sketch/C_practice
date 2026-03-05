#include <stdio.h>

#define ROWSIZE 2
#define COLSIZE 3

int main(){
    int td[ROWSIZE][COLSIZE];

    for(int row = 0 ; row < ROWSIZE ; row++){
        for(int col = 0 ; col < COLSIZE ; col++){
            td[row][col] = (row*COLSIZE)+(col+1);
        }
    }

    printf("반복문 for를 사용하여 출력\n");
    for(int row = 0 ; row < ROWSIZE ; row++){
        for(int col = 0 ; col < COLSIZE ; col++){
            printf("td[%d][%d] == %d  ", row,col,td[row][col]);
            
        }
        printf("\n");
    }
    return 0;

}