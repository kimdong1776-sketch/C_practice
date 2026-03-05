#include <stdio.h>
#include <stdlib.h>

int main(){
    char fname[] = "grade.txt";
    char name_score[80] = {0};
    int cnt = 0;
    FILE *f;
    if ((f = fopen(fname, "w")) == NULL){
        printf("파일이 열리지 않습니다.\n");
        exit(1);
    }
    fprintf(stdout,"이름과 성적(중간, 기말)을 입력하세요.\n");
    fgets(name_score, 80, stdin);

    while(!feof(stdin)){
        fprintf(f, "%d ", ++cnt);
        fputs(name_score, f);
        
        fgets(name_score, 80, stdin);
    }
    fclose(f);

    return 0;
}