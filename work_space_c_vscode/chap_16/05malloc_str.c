#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 20

int main(){
    char *list[10] = {NULL};
    char msg[MAX_LEN] = {0};
    for(int i = 0; i<10;i++){   
        list[i] = (char * )malloc(sizeof(char)*MAX_LEN);
        if(list[i]==NULL){
            printf("말록 페일");
            exit(1);
        }
        sprintf(msg, "TEST string:: %02d", i+1);
        strcpy(list[i], msg);

    }
    for(int i = 0 ; i < 10; i++){
        printf("%s\n", list[i]);

    }
    return 0;
}