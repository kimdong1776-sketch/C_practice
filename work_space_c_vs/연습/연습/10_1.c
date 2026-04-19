#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node* next;
}node ;

void sortinsert(int item, node **first) {
	node* newnode = (node*)malloc(sizeof(node));
	newnode->next = NULL; newnode->data = item;
	node* cur = *first;
	if (!(*first)||(*first)->data > item) {// 널이면
		newnode->next = *first;
		*first = newnode;
	}
	else{
		while (cur->next != NULL && cur->next->data < item) {
			cur = cur->next;
		}
		newnode->next = cur->next;
		cur->next = newnode;
	}
}

int COMPARE(int a, int b) {
	if (a > b) {
		return 1;
	}
	else if (a == b) {
		return 0;
	}
	return -1;

}

void attach(int i, node** rear) {
	node* newnode = (node*)malloc(sizeof(node));
	newnode->data = i; newnode->next = NULL;
	(*rear)->next = newnode;
	*rear = newnode;
}

node* add(node* first1, node* first2) {
	node* result = (node*)malloc(sizeof(node));
	node* rear = result;
	result->next = NULL;
	while (first1 && first2) {
		switch (COMPARE(first1->data, first2->data)) {
		case 1: //오름차순이니까 b를 너어야함.
			attach(first2->data, &rear);
			first2 = first2->next;
			break;
		case 0:
			attach(first2->data, &rear);
			first2 = first2->next;first1 = first1->next;
			break;
		case -1:
			attach(first1->data, &rear);
			first1 = first1->next;
			break;
		}
		
	}
	node* cur = first1;
	for (;cur;cur = cur->next) {
		attach(cur->data, &rear);
	}
	
	cur = first2;
	for (;cur;cur = cur->next) {
		attach(cur->data, &rear);
	}
	node* temp = result;
	result = result->next;
	free(temp);
	return result;
}


int main() {



	FILE* in1, * in2;
	fopen_s(&in1, "in1.txt", "r");
	fopen_s(&in2, "in2.txt", "r");
	int temp;
	node* first1 = NULL;
	node* first2 = NULL;
	node* c = NULL;
	
	while (fscanf_s(in1 ,"%d", &temp) > 0) {

		sortinsert(temp, &first1);
	}
	while (fscanf_s(in2, "%d", &temp) > 0) {
		sortinsert(temp, &first2);
	}
	
	node* cur = first1;
	for (;cur;cur = cur->next) {
		printf("%d ", cur->data);
	}
	printf("\n");
	cur = first2;
	for (;cur;cur = cur->next) {
		printf("%d ", cur->data);
	}
	printf("\n");
	c = add(first1, first2);
	cur = c;
	for (;cur;cur = cur->next) {
		printf("%d ", cur->data);
	}
}