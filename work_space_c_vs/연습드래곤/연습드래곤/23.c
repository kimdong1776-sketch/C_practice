#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
	char data[6];
	struct node* next;
}node;

int myHash(char* src) {
	int t = 0;
	for (int i = 0; i < strlen(src); i++) {
		t += src[i];
	}
	return t;
}
int search(node** hashT, char* src, int D) {
	int key = myHash(src);
	int idx;
	for (int i = 0; i < D; i++) {
		idx = (key + i) % D;
		if (!hashT[idx]) {
			return -1;
		}
		for (node* cur = hashT[i];cur; cur = cur->next) {
			if (!strcmp(hashT[idx]->data, src)) {
				return idx;
			}
		}
	}
	return -1;
}

void insert(node** hashT, char* src, int D) {
	int key = myHash(src);

	
	int idx = key % D;
	node* newnode = (node*)calloc(1, sizeof(node));
	strcpy_s(newnode->data, strlen(src) + 1, src);
		
	if (!hashT[idx]) {
		hashT[idx] = newnode;
	}
	else {
		newnode->next = hashT[idx];
		hashT[idx] = newnode;
	}
	
}

void printTable(node** hash, int D) {
	printf("Hash table:\n");
	for (int i = 0; i < D; i++) {
		printf("%d:", i);
		if (hash[i]) {
			for (node* cur = hash[i];cur; cur = cur->next) {
				printf("%s (%d)", cur->data, myHash(cur->data));
			}
		}
		printf("\n");
	}
}

int main() {
	FILE* in;
	fopen_s(&in, "in.txt", "r");
	if (!in) exit(1);
	int D;

	printf("<scanf>");
	scanf_s("%d", &D);

	node** arr = (node**)calloc(D, sizeof(node*));
	char tmp[6];
	while (fscanf_s(in, "%s", tmp, sizeof(tmp)) > 0) {
		insert(arr, tmp, D);
	}

	printTable(arr, D);

}