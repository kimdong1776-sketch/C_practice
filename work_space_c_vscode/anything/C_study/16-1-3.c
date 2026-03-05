#include <stdio.h>

void scan_score(int (*data)[5]){
    char *subject[] = {"국어", "영어", "수학", "국사"};
    char *name[] = {"철희", "철수", "영희", "영수"};
    int sum_row_score = 0;
    int score = 0;

    for(int i = 0 ; i < 4 ; i++){
        sum_row_score= 0;
        for(int j = 0 ; j < 4 ; j++){
            printf("%s의 %s 과목 점수를 입력해주세요 >>", name[i] , subject[j]);
            scanf("%d", &score);
            data[i][j] = score;
            sum_row_score += score;
        }
        data[i][4] = sum_row_score;
        printf("\n");
    }
}

void cal_score(int (*data)[5]){
    int sum_colum_score = 0;

    for(int i = 0 ; i < 5 ; i++){
        sum_colum_score = 0;
        for(int j = 0 ; j < 4 ; j++){
            sum_colum_score += data[j][i];
        }
        data[4][i] = sum_colum_score;
    }
}

void print_score(int (*data)[5]){
    for(int i = 0 ; i < 5 ; i++){
        for(int j = 0 ; j < 5 ; j++){
            printf("%3d  ", data[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int data[5][5] = {0};
    
    
    scan_score(data);
    cal_score(data);

    print_score(data);
    
}