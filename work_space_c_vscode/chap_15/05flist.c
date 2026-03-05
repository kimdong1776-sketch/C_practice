#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *f;
    if ((f = fopen("05flist.c", "r"))==NULL){
        printf("파일 안열림\n");
        exit(1);
    }
    int ch, cnt = 0;
    printf("%4d: ", ++cnt);
    while((ch = fgetc(f) )!= EOF){
        
        putchar(ch);

        if(ch == '\n'){
            printf("%4d: ", ++cnt);
        }
    }
    printf("\n");
    fclose(f);

    return 0;
}