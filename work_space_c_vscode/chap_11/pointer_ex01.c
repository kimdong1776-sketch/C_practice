#include <stdio.h>

int main(){
    int data = 100;
    int* ptrint = &data;

    printf("ptrint: %p\n", ptrint);

    printf("*ptrint: %d\n", *ptrint);
    return 0;
}