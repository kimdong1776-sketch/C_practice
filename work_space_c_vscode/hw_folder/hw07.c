/******************************************************
 *	- File:	hw07.c
 *	- ID:	2025003170
 *	- Name:	김  동후
 ******************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LOTTO_NUM 6

int	duplicate(int rand_num, int (*lotto)[LOTTO_NUM], int current_row ,int current_colum);

void print_lotto(int (*lotto)[LOTTO_NUM]);	

int main(){
    int lotto[5][6] = {0};
    int joongbock = 0;
    int r_num = 0;
    srand(time(NULL));
    for(int i = 0; i < 5 ; i++){
        for(int j = 0 ; j < LOTTO_NUM; j++){
            joongbock = 0;
            r_num = ((rand()%45) + 1);
            joongbock = duplicate(r_num, lotto, i,j);
            if( joongbock == 0){ //중복이 아니면.
                lotto[i][j] = r_num;
                continue;
            }
            j--;
        }
    }
    print_lotto(lotto);
    
}

int duplicate(int rand_num, int (*lotto)[LOTTO_NUM], int current_row ,int current_colum){
    for(int i = 0; i < current_colum ; i++){
        if(lotto[current_row][i] == rand_num){
            return 1;
        }

    }
    return 0;
}

void print_lotto(int (*lotto)[LOTTO_NUM]){
    printf("Random Generated Lotto Numbers\n");
    for(int i = 0; i < 5 ; i++){
        printf("[%d]:", i+1);
        for(int j = 0 ; j < LOTTO_NUM; j++){
            printf("%3d", lotto[i][j]);
        }
        printf("\n");
     }
}
