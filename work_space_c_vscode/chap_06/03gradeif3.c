#include <stdio.h>

int main(){

    int point = 98;

    if(point>=90)
        printf("A\n");
    if(point>=80)
        printf("B\n");
    if(point>=70)
        printf("C\n");
    if(point>=60)
        printf("D\n");
    else
        printf("F\n");

    return 0;
}