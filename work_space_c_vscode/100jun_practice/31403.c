#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void combine(char * arr, int * num){
    int i = 0;
    int temp[12] = {0};
    while(*num > 0){
        temp[i] = *num % 10 + '0';
        *num /= 10;
        i++;
    }

    for(int j = 0; j<i; j++){
        arr[j] = temp[i-j-1];
    }

}

int main(){
    int A = 0;
    int B = 0;
    int C = 0;
    char A_arr[12] = {0}, B_arr[12] = {0}, C_arr[12] = {0};
    char arr[13] = {0};
    int result = 0;
    scanf("%d", &A);
    scanf("%d", &B);
    scanf("%d", &C);
    printf("%d\n", A+ B -C);

    combine(A_arr, &A);
    combine(B_arr, &B);

    strcat(arr, A_arr);
    strcat(arr, B_arr);
    result = atoi(arr) - C;
    printf("%d", result);

}
