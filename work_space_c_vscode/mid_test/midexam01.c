/******************************************************
*	- File:	midexam01.c	
*	- ID:	2025003170	
*	- Name:	김  동후
******************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void random1darray(int*, int);
void transform(int *ary1D, int ary2d[][6], int, int);

int main (){
    int randomarray[12] = {0};
    int array2d[2][6] = {0};

    random1darray(randomarray, 12);
    transform(randomarray, array2d, 2, 6);

    return 0;
}

void random1darray(int*ary,int n){
    srand(time(NULL));
    printf("Create a 1D array\n");
    for(int i = 0; i < n; i++){
        ary[i] = (rand() % 41) + 10;
        printf("%3d ", ary[i]);
    }
    printf("\n\n");
    
}

void transform(int *ary1D, int ary2D[][6], int row, int colum){
    int k = 0;
    printf("Transform From 1D array to 2D array(2X6)\n");
    for(int i = 0 ; i < row ; i++){
        for(int j = 0 ; j < colum ; j++){
            if(i == 0){
                ary2D[i][j] = ary1D[j];
                printf("%3d ", ary2D[i][j]);
            }
            else{
                k = j + 6;
                ary2D[i][j] = ary1D[k];
                printf("%3d ", ary2D[i][j]);
            }
            
        }
        printf("\n");
    }
    
}