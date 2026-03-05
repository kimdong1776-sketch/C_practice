#include <stdio.h>

int main(){

    int arry[] = {1,2,3,4,5,6};
    int temp;
    int * ptr_s = arry, * ptr_f = &arry[5];

    for(int i = 0; i < 3; i++){
        temp=*(ptr_s+i);
        *(ptr_s+i) = *(ptr_f-i);
        *(ptr_f-i) = temp;

    }
    for(int i = 0; i < 6 ; i++){
        printf("%d", arry[i]);
    }

}
