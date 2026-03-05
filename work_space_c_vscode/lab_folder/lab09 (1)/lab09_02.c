/******************************************************
*	Lab	08.	문자와 문자열
*	- File:	lab09_02.c
*	- ID:	2025003170	
*	- Name:	김  동후
******************************************************/
#include<stdio.h>
#include<string.h>

int str_chr(char * str,char c){
    int count = 0;
    for(int i = 0 ; i < strlen(str); i++){

        if(str[i] == c){
            count++;
        }
    }
    return count;
}

int main(){
    char str[100];
    char c = 0;
    printf("Type a string: ");
    fgets(str, sizeof(str), stdin);
    printf("Type a char to count: ");
    c = getchar();
    printf("The number of %c: %d", c, str_chr(str, c));
}