/******************************************************
*	Lab	09.	문자와 문자열
*	- File:	lab09_01.c
*	- ID:	2025003170	
*	- Name:	김  동후
******************************************************/
#include<stdio.h>
#include<string.h>
void delete_space(char *src, char *dest);

int main(){
    char str[100]= {0};
    char dest[100];
    printf("Type a sentence: ");
    fgets(str, sizeof(str), stdin);
    printf("Original: %s", str);
    delete_space(str, dest);
    printf("NO space: %s", dest);
}

void delete_space(char *src, char *dest){
    int j = 0;
    for(int i = 0 ; src[i] != 0 ; i++){
        if (src[i] != ' ' && src[i] != '\n'){
            dest[j++] = src[i];
        }
    }
    dest[j] = 0;
}