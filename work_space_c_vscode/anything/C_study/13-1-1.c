#include<stdio.h>

int main(){
    int ary[] = {1,2,3,4,5};
    int* ptr1 = ary;
    int* ptr2 = ary;
    for(int i = 0 ; i < 5; i++){
        *(ptr1+i) += 2;
        printf("%d", ary[i]);
    }
    for(int i = 0 ; i < 5; i++){
        *ptr2 += 2;
        ptr2++;
        printf("%d", ary[i]);
    }
    
}