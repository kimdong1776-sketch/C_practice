/******************************************************
 *	Lab	08.	포인터와 배열
 *	- File:	lab08_02.c
 *	- ID:	2025003170
 *	- Name:	김  동후
 ******************************************************/
#include <stdio.h>

void input_value(int (*array)[3], int row, int col);

void transform(int (*array1)[3], int (*array2)[3], int row, int col);

void print_array(int (*array)[3], int row, int col);

int main (){
    int array1[3][3] = {0};
    int array2[3][3] = {0};
    printf("Array Initialization(1~9)\n");
    input_value(array1,	3,	3);	
    print_array(array1,	3,	3);
    printf("Swap rows and columns of array1\n");
   
    transform(array1, array2,	3,	3);
    printf("Print array2\n");
    print_array(array2,	3,	3);
    return 0;
}

void input_value(int (*array)[3], int row, int col){
    int count = 1;
    for(int i = 0 ; i < 3 ; i++){
        for(int j = 0 ; j < 3 ; j++){
            *(*(array + i) + j) = count;
            count++;
        }
    }
}

void transform(int (*array1)[3], int (*array2)[3], int row, int col){
    
    for(int i = 0 ; i < 3 ; i++){
        for(int j = 0 ; j < 3 ; j++){
            *(*(array2 + j) + i) = *(*(array1 + i) + j);
        }
    }
}

void print_array(int (*array)[3], int row, int col){

    for(int i = 0 ; i < 3 ; i++){
        for(int j = 0 ; j < 3 ; j++){
            printf("%d ", *(*(array + i) + j));
        }
        printf("\n");
    }

}