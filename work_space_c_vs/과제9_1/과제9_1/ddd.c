#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node* next;
}node;

int main() {
	FILE* in;
	fopen_s(&in, "in.txt", "r");
	int temp;
	if (in == NULL) {
		fprintf(stderr,"err");
		exit(1);
	}
	node* first = NULL, * end = NULL, * cur = NULL;
	while (fscanf_s(in, "%d", &temp) != EOF) {
		node* new_node = (node*)malloc(sizeof(node));
		new_node->data = temp;
		new_node->next = NULL;

		if (first == NULL) {//빈 리스트
			first = new_node;
			end = new_node;
		}
		else{
			end->next = new_node;
			end = new_node;
		}
	}
	cur = first;
	printf("L: ");
	while (cur != NULL) {
		printf("%d ", cur->data);
		cur = cur->next;
	}
	int fn;
	

	while (1) {
		printf("\n(scanf 입력) ");
		scanf_s("%d", &fn);
		if (fn < 1) {
			break;
		}
		cur = first;
		while (first != NULL && first->data == fn) {
			node* temp = first; // free하기 위해서
			first = first->next;
			free(temp);
		}

		cur = first;
		while (cur != NULL && cur->next != NULL) {
			if (cur->next->data == fn) {
				node* temp = cur->next; // free하기 위해서
				cur->next = cur->next->next; // 끊고 뒤에거랑 붙이기
				free(temp);

			}
			else {
				cur = cur->next;
			}
		}
		if (cur == NULL) {
			printf("Not exits");
			break;
		}
		cur = first;
		printf("L: ");
		while (cur != NULL) {
			printf("%d ", cur->data);
			cur = cur->next;
		}
	}



	cur = first;
	while (cur != NULL) {
		node* curr = cur->next;
		free(cur);
		cur = curr;
	}
}