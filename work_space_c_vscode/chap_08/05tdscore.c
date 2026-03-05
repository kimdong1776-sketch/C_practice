#include <stdio.h>

#define ROWSIZE 4
#define COLSIZE 2

int main(){
    int sum = 0, midsum=0, finalsum = 0;
    int score[ROWSIZE][COLSIZE] = {
        {95,85},
        {90,88},
        {86,90},
        {88,78}};
    printf("  중간 기말\n");
    printf("---------------\n");
    for(int row = 0 ; row < ROWSIZE ; row++){
        for(int col = 0 ; col < COLSIZE ; col++){
            printf("%10d ", score[row][col]);
            sum += score[row][col];
            if (col == 0){ //중간고사면 중간고사 합에 더하고
                midsum += score[row][col];
            }
            else{           //기말고사면 기말고사 합에 더하기
                finalsum += score[row][col];
            }
            
        }
        puts("");
    }
    printf("--------------\n");
    printf("평균: %6.2f %10.2f\n", (double)midsum / ROWSIZE, (double)finalsum / ROWSIZE);
    printf("\n성적의 합은 %d이고 ",sum);
    printf("평균은 %.2f이다. \n",(double)sum / (ROWSIZE * COLSIZE));

    return 0;
}