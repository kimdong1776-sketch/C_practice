#include <stdio.h>

int main(){
    int a[5] = {1,2,3,4,5};
    int b[5] = {1,2,3,4,5};
    int equal = 1;

    for(int i = 0 ; i < 5 ; i ++){
        if(a[i] != b[i]){
            equal = 0;
            break;
        }
    }

    if (equal ==1){
        printf("배열 a와 b는 같습니다");
    }
    else{
        printf("배열 a와 b는 다릅니다.");
    }
    return 0;
}