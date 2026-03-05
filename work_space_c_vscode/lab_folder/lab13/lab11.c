/******************************************************
*	Lab	13. 동적 메모리
*	- File:	lab13.c
*	- ID:	2025003170	
*	- Name:	김  동후
******************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct contacts{
    char name[30];
    char mobile_phone[30];
} CONTACTS;

int main(){
    int num;
    CONTACTS *ptr = NULL;
    printf("Type the number of address: ");
    scanf("%d",&num);
    getchar();
    ptr = (CONTACTS *)malloc(sizeof(CONTACTS)*num);

    for(int i = 0 ; i < num ; i++){

        printf("Type a name: ");
        fgets((ptr+i)->name,30,stdin);
        (ptr+i)->name[strlen((ptr+i)->name)-1] = '\0';


        printf("Type a phone number: ");
        fgets((ptr+i)->mobile_phone,30,stdin);
        (ptr+i)->mobile_phone[strlen((ptr+i)->mobile_phone)-1] = '\0';
    }
    
    printf("===============================================\n");
    printf("%15s %15s", "Name", "Mobile Phone\n");
    printf("===============================================\n");

    for(int i= 0; i < num; i++){
        printf("%15s %15s\n", (ptr+i) -> name, (ptr+i) -> mobile_phone);
    }
    printf("===============================================\n");

    free(ptr);
}