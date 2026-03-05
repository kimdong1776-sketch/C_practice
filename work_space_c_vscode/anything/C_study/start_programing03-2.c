#include <stdio.h>
#include <string.h>

void printf_arr(int (*arr)[30], int width){
    for(int i = 0 ; i< width ; i++){
        for(int j = 0 ; j< width; j++){
            printf("%3d ", arr[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int num = 0;
    int arr[30][30] = {0};
    int count = 1;
    scanf("%d", &num);
    int top = 0;
    int bottom = num - 1;
    int left = 0;
    int right = num -1;

    int rotate = 0;

    while(count <= num * num){
        if(rotate % 4== 0){
            for(int i = left; i <= right; i++){
                arr[top][i] = count;
                count++;
            }
            top++;
        }
        else if(rotate % 4 == 1){
            for(int i = top; i <= bottom; i++){
                arr[i][right] = count;
                count++;
            }
            right--;
        
        }
        else if(rotate % 4 == 2){
            for(int i = right ; i >= left; i--){
                arr[bottom][i] = count;
                count++;
            }
            bottom--;
        }
        else{
            for(int i = bottom; i >= top ; i--){
                arr[i][left] = count;
                count++;
            }
            left++;
        }
        rotate++;
    }
    printf_arr(arr, num);
}