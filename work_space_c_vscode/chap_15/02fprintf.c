#include <stdio.h>
#include <stdlib.h>

int main(){
    char fname[] = "grade.ㅅㅌㅅ";
    FILE *f;
    char name[30];
    int point1, point2, cnt = 0;

    if ((f = fopen(fname, "w")) == NULL){
        printf("파일이 열리지 않았습니다.\n");
        exit(1);
    }

    printf("이름과 성적(중간, 기말)을 입력하세요.\n");
    scanf("%s %d %d", name, &point1, &point2);

    fprintf(f, "%d %s %d %d\n",++cnt ,name, point1, point2);

    fclose(f);

    if((f = fopen(fname, "r"))==NULL){
        printf("파일이 열리지 않았습니다. \n");
        exit(1);
    }
    fscanf(f,"%d %s %d %d\n", &cnt, name, &point1, &point2);

    fprintf(stdout, "%-4s %-10s %-10s %-s\n", "번호", "이름", "중간", "기말");
    fprintf(stdout, "%-4d %-12s %-10d %-d\n", cnt, name,point1 ,point2);
    
    fclose(f);
    return 0;
}