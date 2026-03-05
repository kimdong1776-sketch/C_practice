#include <stdio.h>

int add(int a, int b);
int findMin(int a, int b);

int main(){

    int a =3, b=5;

    int sum = add(a,b);

    printf("합: %d \n", sum);

    printf("작은 값: %d\n", findMin(a,b));
    return 0;
}

int add(int a, int b){
    int sum = a + b;

    return sum;
}

int findMin(int x, int y){
    int min  = (x<y ? x : y);
    return min;
}