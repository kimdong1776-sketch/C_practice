#include <stdio.h>

int main(){
    int arr[][9] = {0};
    for(int i = 2; i < 5;i++){
        for(int j = 1; j < 10; j++){
            arr[i][j] = i*j;
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }
}