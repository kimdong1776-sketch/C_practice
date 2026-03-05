#include<stdio.h>

void swap(int* n1, int* n2, int *n3){
    int temp = *n3;
    *n3 = *n2;
    *n2 = *n1;
    *n1 = temp;
    printf("%d %d %d", *n1, *n2, *n3);
}

int main(){
    int num1 =1, num2 = 2, num3 =3;
    swap(&num1, &num2, &num3);

}