#include "linkedlist.h"

extern LINK creatNode(char *name);
extern LINK append(LINK head, LINK cur);
extern int printList(LINK head);

void get_name(char *name, int len){

    fgets(name, len,stdin);
    name[strlen(name)+1] = '\0';
}

int main(){
    char name[30] = {0};
    LINK head =NULL;
    LINK cur;
    printf("이름을 입력하고 Endter를 누르세요. >>\n");
    get_name(name, sizeof(name));

    while(!feof(stdin)){
        cur = creatNode(name);
        if(cur == NULL){
            printf("동적 메모리 할당에 문제가 있습니다.\n");
            exit(1);
        }
        head = append(head, cur);
        printList(head);
        get_name(name, sizeof(name));
    }


    return 0;
}