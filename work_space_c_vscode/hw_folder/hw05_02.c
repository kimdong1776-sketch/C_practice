/******************************************************
*	- File:	hw05_02.c
*	- ID:	2025003170	
*	- Name:	김  동후
******************************************************/

#include <stdio.h>
#define ID 3

int main(){
    int data[ID][5] = {
        {85, 98, 87, 76, 100},
        {96, 89, 96, 92, 96},
        {63, 72, 55, 49, 88}
    };
    double temp_sum;
    double per[]={0.3, 0.4, 0.2, 0.05, 0.05}; 
    double score[ID][6] = {0};

    printf("--------------------------------------------\n");
    printf("학번  중간   기말   과제   퀴즈   출석   합계\n");
    printf("--------------------------------------------\n");
    for(int i = 0; i < ID; i++){ 
        printf(" %d",i+1);
        temp_sum = 0.0;
        for(int j = 0; j < 5; j++){ 
            score[i][j] = data[i][j] * per[j];
            temp_sum += score[i][j];
            printf("%7.1f", score[i][j]);
        }
        score[i][5] = temp_sum;
        printf("%7.1f\n", score[i][5]);
    }
    printf("--------------------------------------------");
    return 0;
}