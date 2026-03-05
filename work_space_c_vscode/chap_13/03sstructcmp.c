#include<stdio.h>
#include<string.h>

struct student{
    int snum;
    char *dept;
    char name[12];
};

int main(){
    struct student hong = {
        20220001,
        "Computer Engineering",
        "Hong"
    };
    struct student na = {202200002};
    struct student you = {202200003};

    printf("Type a student's name: ");

    scanf("%s", na.name);

    
    na.dept = "Electronic Engineering";
    you.dept = "Mechanical Engineering";
    memcpy(you.name, "Alice", 6);
    strcpy(you.name, "Alice");

    printf("[%d, %s, %s]\n", hong.snum, hong.dept, hong.name );
    printf("[%d, %s, %s]\n", na.snum, na.dept, na.name );
    printf("[%d, %s, %s]\n\n", you.snum, you.dept, you.name );

    struct student one;
    one = you;
    if(one.snum == you.snum){
        printf("학번이 %d로 동일합니다.\n", one.snum);
    }

    if(one.snum == you.snum && !strcmp(one.name, you.name)&&!strcmp(one.dept, you.dept)){
        printf("내용이 같은 구조체 입니다.\n");
    }
}