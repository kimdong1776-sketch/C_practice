#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int fwirt_ex(){
    int buffer[SIZE] = {10,20,30,40,50};
    FILE *fp = NULL;
    fp = fopen("binary.bin", "wb");

    if(fp == NULL){
        fprintf(stderr, "binary.bin 파일을 열 수 없습니다.");
        exit(1);
    }
    fwrite(buffer, sizeof(int), SIZE, fp);
    fclose(fp);
    return 0;
}

int fread_ex(){
    int buffer[SIZE];
    FILE *fp = NULL;
    int cnt = 0;

    fp = fopen("binary.bin", "rb");
    if(fp == NULL){
        fprintf(stderr, "binary.bin 파일을 열 수 없습니다.");
        exit(1);
    }
    cnt = fread(buffer, sizeof(int), SIZE, fp);
    for(int i = 0; i < cnt; i++){
        printf("%d", buffer[i]);
    }
    printf("\n");
    fclose(fp);
    return 0;
}

int main(){
    fwirt_ex();
    fread_ex();
    return 0;
}