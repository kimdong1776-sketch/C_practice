#include <stdio.h>
#include <stdlib.h>


typedef struct node {
	int data;
	struct node* next;
}node;

int main() {
	FILE* in;
	fopen_s(&in,"in.txt", "r");
	int n = 0;

	node* first = 0, * end = 0;
 	while (fscanf_s(in, "%d", &n) != EOF) {
		node* newnode = (node*)malloc(sizeof(node));
		newnode->data = n; newnode->next = NULL;
		if (!first) {
			first = newnode;
			end = newnode;
		}
		else {
			newnode->next = first;
			first = newnode;
		}
	}
	for (node* cur = first; cur != NULL; cur = cur->next) {
		printf("%d ", cur->data);
	}
	while (first != NULL && first->data % 2 == 0) {
		node* temp = first;
		first = first->next;
		free(temp);
	}


	node* cur = first;
	while (cur != NULL && cur->next != NULL) {
		if (cur->next->data % 2 == 0) {
			node* temp = cur->next;
			cur->next = cur->next->next;
			free(temp);
			
		}
		else {
			cur = cur->next;
		}
	}
	printf("\n");
	for (node* cur = first; cur != NULL; cur = cur->next) {
		printf("%d ", cur->data);
	}
		
	
}
