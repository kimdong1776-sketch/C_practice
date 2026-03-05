/******************************************************
*	Lab	10.	구조체
*	- File:	lab09_01.c
*	- ID:	2025003170	
*	- Name:	김  동후
******************************************************/
#include <stdio.h>
#include <string.h>


typedef struct{
    char title[50];
    char receiver[50];
    char sender[50];
    char content[100];
    char date[20];
    int proirity;
}Email;

char *label[] = {
    "Title", 
    "Receiver", 
    "Sender", 
    "Content",
    "Date", 
    "Proirity"
};

void print_email(Email e){
    printf("--------------------------------\n");
    printf("%s:%s", label[0], e.title);
    printf("%s:%s", label[1], e.receiver);
    printf("%s:%s", label[2], e.sender);
    printf("%s:%s", label[3], e.content);
    printf("%s:%s", label[4], e.date);
    printf("%s:%d", label[5], e.proirity);
    printf("\n--------------------------------");
}



int main(){
    Email email;
    memset(&email, 0, sizeof(Email));
    printf("input email data\n");

    printf("%s: ", label[0]);
    fgets(email.title, sizeof(email.title) ,stdin);

    printf("%s: ", label[1]);
    fgets(email.receiver, sizeof(email.receiver) ,stdin);
    email.receiver[strlen(email.receiver)-1] = '\0';
    strcat(email.receiver, "@knu.ac.kr\n");

    printf("%s: ", label[2]);
    fgets(email.sender, sizeof(email.sender) ,stdin);
    email.sender[strlen(email.sender)-1] = '\0';
    strcat(email.sender, "@knu.ac.kr\n");

    printf("%s: ", label[3]);
    fgets(email.content, sizeof(email.content) ,stdin);
    
    printf("%s ", label[4]);
    fgets(email.date, sizeof(email.date) ,stdin);

    printf("%s(0: Urgent. 1: Normal): ", label[5]);
    scanf("%d", &email.proirity);

    print_email(email);

    return 0;
}