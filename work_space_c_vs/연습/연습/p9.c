#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node* next;
}node;

void P1() {
	FILE* in;
	fopen_s(&in, "in.txt", "r");
	int temp;
	node* k;
	node* first = 0, * end = 0;
	while (fscanf_s(in, "%d", &temp) > 0) {
		node* newnode = (node*)malloc(sizeof(node));
		newnode->next = NULL; newnode->data = temp;
		if (first) {
			end->next = newnode;
			end = newnode;
		}
		else {
			first = newnode;
			end = newnode;
		}
	}
	node* cur = first;
	for (;cur;cur = cur->next) {
		printf("%d (%u)\n",cur->data, cur);
	}
	cur = first;
	for (;cur;) {
		k = cur;
		cur = cur->next;
		free(k);
	}
	fclose(in);
	
}

void P2() {
	FILE* in;
	fopen_s(&in, "in.txt", "r");
	int temp;
	node* k;
	node* first = 0;
	while (fscanf_s(in, "%d", &temp) > 0) {
		node* newnode = (node*)malloc(sizeof(node));
		newnode->next = NULL; newnode->data = temp;

		if (first) {
			newnode->next = first;
			first = newnode;
		}
		else {
			first = newnode;
		}
	}
	node* cur = first;
	for (;cur;cur = cur->next) {
		printf("%d (%u)\n", cur->data, cur);
	}
	cur = first;
	for (;cur;) {
		k = cur;
		cur = cur->next;
		free(k);
	}
	fclose(in);
}

void P3() {
	FILE* in;
	fopen_s(&in, "in.txt", "r");
	int temp;
	node* k;
	node* first = 0; node* end = 0;
	while (fscanf_s(in, "%d", &temp) > 0) {
		node* newnode = (node*)malloc(sizeof(node));
		newnode->next = NULL; newnode->data = temp;
		if (temp % 2) {
			if (!first) {
				first = newnode;
				end = newnode;
			}
			end->next = newnode;
			end = newnode;
		}
		else{
			newnode->next = first;
			first = newnode;
		}
		
	}
	node* cur = first;
	for (;cur;cur = cur->next) {
		printf("%d (%u)\n", cur->data, cur);
	}
	cur = first;
	for (;cur;) {
		k = cur;
		cur = cur->next;
		free(k);
	}
	fclose(in);
}

int main() {

	FILE* in;
	fopen_s(&in, "in.txt", "r");

	P1();
	P2();
	P3();

}