#include <stdio.h>

void change_number(int *pnum1, int *pnum2){

    printf("\n");
    printf("1. *pnum1: %d, *pnum2: %d\n", *pnum1, *pnum2);

    *pnum1 = *pnum1 + 100;
    *pnum2 = *pnum2 + 200;
    printf("2. *pnum1 : %d, *pnum2: %d\n", *pnum1, *pnum2);
    printf("\n");
}

int main(){
    int n1 = 10, n2 = 20;
    printf("before change_num() n1= %d. n2 = %d\n", n1, n2);
    change_number(&n1, &n2);
    printf("After change_number() n1 = %d, n2 = %d\n", n1, n2);
    return 0;
}
