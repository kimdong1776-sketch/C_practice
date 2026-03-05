#include <stdio.h>

void recuresive(int num){
    if(num > 8){
        return;
    }
    recuresive(num + 1);
    printf("recuresive call!! %d \n", num);
}

int main(){
    int num = 0;
    recuresive(num);
    return 0;
}