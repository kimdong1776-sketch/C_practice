/******************************************************
*	- File:	hw06_race.c
*	- ID:	2025003170	
*	- Name:	김  동후
******************************************************/

#include	<stdio.h>	
#include	<time.h>	
#include	<stdlib.h>	
#include	<unistd.h>	

int Move_Tortoise(int, int*);
int Move_Hare(int, int*);

int main(){ //시간, 심판 역할
    int tortoise_pos = 0, hare_pos = 0;
    int running = 1;
    char ch;
    int step_T[] = {3, -6, 1};
    int step_H[] = {0, 9, -12, 1, -2};
    srand(time(NULL));
    
    printf("T(%d)\n", tortoise_pos);
    printf("H(%d)\n", hare_pos);
    printf("Type Enter to Start Race !!");	
    scanf("%c",	&ch);
    // 단순히 Enter키를 입력할 때까지 대기하기 위해 사용
    while(running){
        printf("------------------------------------------------------------------------\n");
        tortoise_pos = Move_Tortoise(tortoise_pos,step_T);
        hare_pos = Move_Hare(hare_pos,step_H);
        usleep(300*1000);


        if (tortoise_pos == 50||hare_pos == 50){
            running = 0;
        }
    }  
    printf("------------------------------------------------------------------------\n");  
    if (tortoise_pos > hare_pos){
        printf("Tortoise Win!(Tortoise:%d,Hare:%d)", tortoise_pos, hare_pos);
    }
    else if (tortoise_pos < hare_pos){
        printf("Hare Win!(Tortoise:%d,Hare:%d)", tortoise_pos, hare_pos);
    }
    else{
        printf("Even Game!(Tortoise: %d,Hare: %d)", tortoise_pos, hare_pos);
    }
}



int Move_Tortoise(int pos, int *step){  // 랜덤 값, 이동거리 출력
    int r_num, current_pos = 0, index = 0;
    // int step[] = {3, -6, 1};
    r_num = rand() % 10 + 1;

    if(r_num < 6){ // 1~5
        index = 0;
    }
    else if(r_num < 8){ //6~7
        index = 1;
    }
    else{               // 8~10
        index = 2;
    }

    current_pos = pos + step[index];
    for(int i=0; i < current_pos;i++){
        printf(" ");
    }
    if (current_pos <= 0){
        current_pos = 0;
    }
    if (current_pos > 50){
        current_pos = 50;
    }
    printf("T(pos: %d, step: %d\n",current_pos, step[index]);
    return current_pos;
}

int Move_Hare(int pos, int *step){ // 랜덤 값, 이동거리 출력
    int r_num, current_pos = 0, index = 0;
    // int step[] = {0, 9, -12, 1, -2};
    r_num = rand() % 10 + 1;

    if(r_num < 3){ // 1~2
        index = 0;
    }
    else if(r_num < 5){ //3~4
        index = 1;
    }
    else if(r_num < 6){ //5
        index = 2;
    }
    else if(r_num < 9){ //6~8
        index = 3;
    }
    else{               // 9~10
        index = 4;
    }

    current_pos = pos + step[index];
    for(int i=0; i < current_pos;i++){
        printf(" ");
    }
    if (current_pos <= 0){
        current_pos = 0;
    }
    if (current_pos > 50){
        current_pos = 50;
    }
    printf("H(pos: %d, step: %d\n",current_pos, step[index]);
    return current_pos;
}
