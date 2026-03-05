#include <stdio.h>
#define MAX 5

void MaxAndMin(int **mxptr, int **mnptr, int*arr ){
    int *max = &arr[0];
    int *min = &arr[0];
    for(int i = 0; i<5;i++){
        if(*max < arr[i]){
            max = &arr[i];
        }
        if(*min > arr[i]){
            min = &arr[i];
        }
    }
    *mxptr = max, *mnptr = min; 
}

int main(){
    int *maxptr;
    int *minptr;
    int arr[MAX];
    printf("5개의 숫자를 입력해주세요\n");
    for(int i = 0; i < MAX;i++){
        printf("입력 >>");
        scanf("%d", &arr[i]);
    }
    MaxAndMin(&maxptr, &minptr, arr);
    printf("maxptr : %p, minptr : %p", maxptr, minptr);
    printf("maxptr : %d, minptr : %d", *maxptr, *minptr);

}