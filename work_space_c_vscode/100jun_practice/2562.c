#include <stdio.h>

int main(){
    int arr[9] = {0};
    int idx = 0;
    int max = arr[0];
    for(int i = 0;i < 9;i++){
        scanf("%d", &arr[i]);
        if(max < arr[i]){
            max = arr[i];
            idx = i;
        }
    }
    printf("%d\n%d", max, idx+1);

}