#include <stdio.h>

int main(){
    char name[20] = {0}, dept[30] = {0};
    int snum;

    printf("학번 이름 학과 입력>>\n");
    scanf("%d %s %s", &snum, dept, name);
    printf("출력: %d %s %s\n\n", snum, dept, name);
    getchar();

    char line[101] = {0};
    printf("한 행에 학번 이름 학과 입력한 후[enter]\n");
    printf("새로운 행에서 (ctrl + z, ctrl d)를 누르십시오.\n");

    while(fgets(line, 101, stdin)){
        puts(line);
    }
    printf("Exit Program\n");
    return 0;
}