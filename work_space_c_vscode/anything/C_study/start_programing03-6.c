#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){
    srand(time(NULL));
    int c_num[3] = {0};
    for(int i = 0; i < 3; i++){
        c_num[i] = rand()%10;
        for(int j = 0; j < i;j++){
            if(c_num[i] == c_num[j]){
                i--;
                break;
            }
        }
    }
    int u_num[3] = {0};

    int strike = 0, ball = 0;

    printf("game start");
    while(strike != 3){
        strike = 0, ball = 0;
        printf("\n3개의 숫자 선택: ");
        scanf("%d %d %d", &u_num[0], &u_num[1],&u_num[2]);
        

        for(int i = 0; i<3;i++){
            for(int j = 0 ; j < 3; j++){
                if(c_num[i] == u_num[j]){
                    ball++;
                }
            }
            if(c_num[i] == u_num[i]){
                strike++;
            }
        }
        ball -= strike;
        printf("\n도전 결과 %d strike, %d ball", strike, ball);
        
    }
    printf("game over");
}