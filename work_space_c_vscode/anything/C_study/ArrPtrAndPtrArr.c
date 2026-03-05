#include <stdio.h>

void complexfunone(int **arr1, int* (*arr2)[5]){
    printf("d");
}
void complexfuntwo(int ***arr3, int *** (*arr4)[4]){
    printf("d");
}


int main(){
    int *arr1[3];
    int *arr2[3][5];
    int ** arr3[5];
    int *** arr4[3][4];
    

   complexfunone(arr1, arr2);
   complexfuntwo(arr3, arr4);
}     
