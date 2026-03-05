#include <stdio.h>

extern int add(int a, int b);
extern int findMax(int, int);
extern int findMin(int, int);
void printMin(int, int);

int main(){
    int a = 10, b = 15;

    int max = findMax(a,b);
    printf("MAX: %d\n", max);
    printf("SUM: %d\n", add(a, b));

    printMin(a, b);

    return 0;
}

void printMin(int a, int b){
    int min = a < b ? a : b;
    printf("MIN: %d\n", min);
}