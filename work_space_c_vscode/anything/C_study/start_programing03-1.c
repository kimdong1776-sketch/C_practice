#include <stdio.h>
#include <string.h>

void dolligi(int (*arr)[4]){
    int temp[4][4] = {0};
    memcpy(temp, arr, sizeof(temp));
    for(int i = 0 ; i<4; i++){
        for(int j = 0; j<4; j++){
            arr[i][j] = temp[i][3-j];
        }
    }
}

void print_arr(int (*arr)[4]){
    for(int i = 0 ; i<4; i++){
        for(int j = 0; j<4; j++){
            printf("%2d ", arr[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int arr[4][4] = {0};
    for(int i = 0 ; i<4; i++){
        for(int j = 0; j<4; j++){
            arr[i][j] = (j+1) + i*4;
        }
    }
    dolligi(arr);

    print_arr(arr);
    dolligi(arr);

    print_arr(arr);
    dolligi(arr);

    print_arr(arr);
    dolligi(arr);

    print_arr(arr);
}