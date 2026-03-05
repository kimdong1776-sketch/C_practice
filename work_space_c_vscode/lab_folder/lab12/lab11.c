/******************************************************
*	Lab	12.	파일처리
*	- File:	lab10.c
*	- ID:	2025003170	
*	- Name:	김  동후
******************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE_MAX 201
int main(){
    
    char fname1[20] = {0};
    char fname2[20] = {0};
    char buf1[LINE_MAX] = {0};
    char buf2[LINE_MAX] = {0};
    printf("Type the first file name: ");
    scanf("%s", fname1);
    printf("Type the second file name: ");
    scanf("%s", fname2);
    if(strcmp(fname1, fname2)==0){
        printf("The tho files are identical.");
    }
    FILE *f1 = fopen(fname1, "r");
    FILE *f2 = fopen(fname2, "r");
    
    if(f1 == NULL || f2 == NULL){
        fprintf(stderr, "파일이 열리지 않습니다.");
        exit(1);
    }

    fgets(buf1,LINE_MAX,f1);
    fgets(buf2,LINE_MAX,f2);
    while(1){
        if(strcmp(buf1, buf2) != 0){
            printf("%s and %s are diffrent\n", fname1, fname2);
            fprintf(stdout,">>%s\n",buf1);
            fprintf(stdout,"<<%s\n",buf2);
            break;
        }
        fgets(buf1,LINE_MAX,f1);
        fgets(buf2,LINE_MAX,f2);
        
    }
    fclose(f1);
    fclose(f2);
    return 0;
}