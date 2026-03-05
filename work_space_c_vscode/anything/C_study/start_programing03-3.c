#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){
    int win = 0, draw = 0;
    char * index[] = {"가위", "바위", "보"};
    int u_num = 0;
    

    srand(time(NULL));

    while(1){
        printf("가위바위보 중 선택하세요 순서대로 0,1,2");
        scanf("%d", &u_num);
        int c_num = rand() % 3;
        printf("당신은 %s선택 컴퓨터는 %s 선택",index[u_num], index[c_num]);
        if(u_num == c_num){
            printf("비겼습니다!\n");
            draw++;
        }
        else if((u_num+1 == c_num)||(u_num - c_num) == 2){
            printf("졌습니다!\n");
            break;

        }
        else{
            printf("이겼습니다!\n");
            win++;
        }
    }
    printf("게임의 결과 %d 승 %d무", win, draw);
}