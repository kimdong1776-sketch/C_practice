#include <stdio.h>

int main(){
    int x = 1;
    int *ptrx = &x;

    printf("ptrx adress: %p\n x address: %p\n", ptrx, &x);
    printf("1. *ptrx = %2d, x = %d\n", *ptrx, x);

    *ptrx += 10;
    printf("1. *ptrx = %2d, x = %d\n", *ptrx, x);
    
    
    x += 10;
    
    printf("3. *ptrx = %2d, x = %d\n", *ptrx, x);
    return 0;
}