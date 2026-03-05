#include <stdio.h>

int main(){
    int value = 0x64636261; //dcba로 저장함 리틀 엔디언 시각화도 가능
    char *pc = (char *)&value;
    int *pi = (int *)&value;

    for(int i = 0 ; i < 4 ; i++){
        printf("(pc+%d): %p, *(pc+%d): %c\n", i, (pc+i), i, *(pc + i));
    }
    printf("\n");

    printf("*pi: 0x%x, %d\n", *pi, *pi);
    for(int i = 0 ; i < 4 ; i++){
        printf("(pi+%d): %p\n", i, pi + i);
    }
    return 0;
}