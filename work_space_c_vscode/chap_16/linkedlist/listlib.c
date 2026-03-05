#include "linkedlist.h"

LINK creatNode(char *name){
    LINK cur = NULL;
    cur = (LINK)malloc(sizeof(NODE));
    if(cur == NULL){
        printf("not creat node");
        return NULL;
    }
    // memset(cur, 0 , sizeof(NODE));
    cur ->name = (char *)malloc(sizeof(char) * (strlen(name) +1));
    strcpy(cur->name, name);
    cur -> next = NULL;

    return cur;

}
LINK append(LINK head, LINK cur){
    LINK nextNode = head;
    if(head == NULL){
        head = cur;
        return head;
    }
    while(nextNode->next != NULL){
        nextNode = nextNode->next;
    }

    nextNode -> next = cur;

    return head;
}
int printList(LINK head){
    int cnt = 0;
    LINK nextNode = head;

     while(nextNode != NULL){
        printf("%3d번째 노드는 %s\n", ++cnt, nextNode -> name);
        nextNode = nextNode -> next;
     }

     return cnt;
}