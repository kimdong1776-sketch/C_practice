#include <stdio.h>

int main(){
    int n = 0;
    scanf("%d", &n);
    int arr[100] = {0};
    int result = 0 ;
    for(int i = 0; i < n ; i++){
        scanf("%1d", arr + i);
        result += arr[i];

    }
    printf("%d", result);
}