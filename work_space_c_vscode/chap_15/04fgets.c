#include <stdio.h>
#include<stdlib.h>

int main(){
    char fname[] = "char.txt";
    FILE *f;
    if((f = fopen(fname, "w"))== NULL){
        printf("파일이 열리지 않습니다.\n");
        exit(1);
    }
    puts("영어 문자를 계속 입력하다가 종료하려면 x를 입력>>");
    int ch;
    while(((ch) = getchar()) != 'x'){
        fputc(ch, f);
    }
    fclose(f);
    puts("");
    if((f = fopen(fname, "r"))== NULL){
        printf("파일이 열리지 않습니다.\n");
        exit(1);
    }
    while((ch = getc(f)) != EOF){
        putchar(ch);
    }

    fclose(f);
    puts("");
    return 0;
}