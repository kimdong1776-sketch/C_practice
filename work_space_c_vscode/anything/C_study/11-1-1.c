#include<stdio.h>

int main(){
    int num[5] = {0};
    int max = 0, min = 0, sum = 0;
    for(int i = 0 ; i < 5 ; i++){
        scanf("%d", &num[i]);  
    }
    max = num[0];
    min = num[0];
    for(int i = 0; i < 5;i++){
        if(max < num[i]){
            max = num[i];
        }
        if(min > num[i]){
            min = num[i];
        }
        sum += num[i];
    }
    printf("max: %d, min : %d, sum : %d", max, min, sum);

    return 0;
}