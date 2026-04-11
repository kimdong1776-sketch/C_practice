#include <stdio.h>
#include <stdlib.h>


typedef struct node {
	int data;
	struct node* next;
}node;



void P1() {
	FILE* in = NULL;
	int temp;
	fopen_s(&in, "in.txt", "r");
	if (in == NULL) {
		exit(1);
	}
	node* first = NULL;
	node* end = NULL;
	node* cur = NULL;

	while (fscanf_s(in, "%d", &temp) != EOF) {
		node* new_node = (node*)malloc(sizeof(node));
		new_node->data = temp;
		new_node->next = NULL;

		if (first == NULL) {//빈 리스트
			first = new_node;
			end = new_node;
		}
		else {
			end->next = new_node;
			end = new_node;
			
			
		}
	}
	cur = first;
	while (cur != NULL) {

		printf("%d (%u)\n", cur->data, cur);
		cur = cur->next;
	}
	cur = first;
	while (cur != NULL) {
		node* curr_node = cur->next;
		free(cur);
		cur = curr_node;
	}
	fclose(in);

}
void P2() {
	FILE* in = NULL;
	int temp;
	fopen_s(&in, "in.txt", "r");
	if (in == NULL) {
		exit(1);
	}

	node* first = NULL;
	node* end = NULL;
	node* cur = NULL;

	
	while (fscanf_s(in, "%d", &temp) != EOF) {
		node* new_node = (node*)malloc(sizeof(node));
		new_node->data = temp;
		new_node->next = NULL;


		if (first == NULL) {
			first = new_node;
			end = new_node;
		}
		else {
			new_node->next = first;
			first = new_node;
		}
	}

	cur = first;
	while (cur != NULL) {

		printf("%d (%u)\n", cur->data, cur);
		cur = cur->next;
	}
	while (cur != NULL) {
		node* curr_node = cur->next;
		free(cur);
		cur = curr_node;
	}
}
void P3() {
	FILE* in = NULL;
	int temp;
	fopen_s(&in, "in.txt", "r");
	if (in == NULL) {
		exit(1);
	}

	node* first = NULL;
	node* end = NULL;
	node* cur = NULL;


	while (fscanf_s(in, "%d", &temp) != EOF) {
		node* new_node = (node*)malloc(sizeof(node));
		new_node->data = temp;
		new_node->next = NULL;


		if (first == NULL) {
			first = new_node;
			end = new_node;
		}
		else {
			if (new_node->data % 2) {// 홀수
				end->next = new_node;
				end = new_node;
			}
			else {//짝수
				new_node->next = first;
				first = new_node;
			}
			
		}
	}

	cur = first;
	while (cur != NULL) {

		printf("%d (%u)\n", cur->data, cur);
		cur = cur->next;
	}
	while (cur != NULL) {
		node* curr_node = cur->next;
		free(cur);
		cur = curr_node;
	}
}



int main() {
	printf("컴퓨터학부 2025003170 김동후\n문제 1:\n");
	P1();
	printf("\n문제 2:\n");
	P2();
	printf("\n문제 3:\n");
	P3();
}