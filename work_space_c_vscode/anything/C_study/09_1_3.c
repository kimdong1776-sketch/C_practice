#include <stdio.h>

void print_pivonach(int n){
    int f1 = 0, f2 = 1, f3;
    if(n == 1){
        printf("0");
    }
    else{
        printf("%d %d ", f1, f2);
    }
    for(int i = 0 ; i < n-2 ; i++){
        f3 = f1 + f2;
        printf("%d ", f3);
        f1 = f2;
        f2 = f3;
    }
}

int main(){
    int num;
    do{
        printf("피보나치 수열을 몇번째 까지 구할까요?(0 = quit)");
        scanf("%d", &num);
        if(num == 0){
            break;
        }
        print_pivonach(num);
    }while(num);
    return 0;
}