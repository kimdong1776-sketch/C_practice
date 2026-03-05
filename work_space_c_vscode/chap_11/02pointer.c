#include <stdio.h>

int main(){

    int data = 100;
    int *ptrint;
    ptrint =  &data;

    printf("변수명 주소값 저장값\n");
    printf("----------------------------------------");
    printf("    data %p %16d\n",&data,data);
    printf("  ptrint %p %16d\n", &ptrint, ptrint); //&ptrint: 포인터 변수 ptrint의 주소임
    printf("  ptrint %p %16d\n", ptrint, *ptrint);

    printf("sizeof(ptrint): %zu", sizeof(ptrint));

    return 0;
}