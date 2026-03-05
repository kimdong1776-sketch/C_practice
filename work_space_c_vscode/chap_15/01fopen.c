#include <stdio.h>
#include<stdlib.h>

int main(){
    char* fname = "basisc.txt";
    FILE* f;

    char name[30] = "손혜진";
    int point = 99;

    if((f=fopen(fname, "w")) == NULL){
        printf("파일이 열리지 않아 종료합니다.\n");
        exit(1);
    }

    fprintf(f, "이름 %s 학생의 성적은 %d 입니다.\n", name, point);
    fclose(f);

    puts("프로젝트 폴더에서 파일 basic.txt를 메모장으로 열어보세요ㅣ");
    printf("이름 %s 학생의 성적은 %d입니다.\n", name, point);

    return 0;
}