/******************************************************
*	- File:	final01.c	
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
    char* b1 = 0,* b2 = 0;
    int indentical = 1;
    printf("Type the first file name: ");
    scanf("%s", fname1);
    printf("Type the second file name: ");
    scanf("%s", fname2);
    FILE *f1 = fopen(fname1, "r");
    FILE *f2 = fopen(fname2, "r");
    
    if(f1 == NULL || f2 == NULL){
        fprintf(stderr, "파일이 열리지 않습니다.");
        exit(1);
    }

    int count =0;
    b1 = fgets(buf1, sizeof(buf1), f1);
    b2 = fgets(buf2, sizeof(buf2), f2);
    while(1){
        count++;
        if(strcmp(buf1, buf2) != 0){
            indentical = 0;
            fprintf(stdout,">>%2d : %s",count, buf1);
            fprintf(stdout,"<<%2d : %s",count, buf2);
        }
        if((b1 == 0) && (b2 == 0)){
            if(indentical){
                printf("The two files are identical.");
            }
            break;
        }
        else if((b1 != 0) && (b2 == 0)){
            while((fgets(buf1, sizeof(buf1), f1))!=NULL){
                count++;
                fprintf(stdout,">>%2d : %s",count, buf1);
            }
        }
        else if((b1 == 0) && (b2 != 0)){
            while((fgets(buf2, sizeof(buf2), f1))!=NULL){
                count++;
                fprintf(stdout,"<<%2d : %s",count, buf2);
            }
        }
        if(b1 != NULL){
            b1 = fgets(buf1, sizeof(buf1), f1);
        }
        if(b2 != NULL){
            b2 = fgets(buf2, sizeof(buf2), f2);  
        }
    }
   
    fclose(f1);
    fclose(f2);
    return 0;
}