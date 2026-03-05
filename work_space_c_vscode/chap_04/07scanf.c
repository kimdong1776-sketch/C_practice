#include<stdio.h>

int main(){
    int year, month, day;
    printf("당신의 생년월일은? ");
    scanf("%d - %d - %d", &year, &month, &day);
    printf("생년월일: %d %d %d", year, month, day);

    return 0;
}