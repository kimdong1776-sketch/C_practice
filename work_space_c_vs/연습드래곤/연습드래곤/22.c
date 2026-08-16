#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
	int data[6];
	struct node* next;
}node;

int myHash(char* src) {
	int t = 0;
	for (int i = 0; i < strlen(src); i++) {
		t += src[i];
	}
	return t;
}
int search(char** hashT, char* src, int D) {
	int key = myHash(src);
	int idx;
	for (int i = 0; i < D; i++) {
		idx = (key + i) % D;
		if (!hashT[idx]) {
			return -1;
		}
		if (!strcmp(hashT[idx], src)) {
			return idx;
		}
	}
	return -1;
}

void insert(char** hashT, char* src, int D) {
	int key = myHash(src);
	int idx;
	for (int i = 0; i < D;i++) {
		idx = (key + i) % D;
		if (!hashT[idx]) {
			hashT[idx] = (char*)calloc(strlen(src)+1, sizeof(char));
			strcpy_s(hashT[idx],strlen(src)+1, src);
			return;
		}
	}
	printf("hash table overflow");
}

void printTable(char** hash, int D) {
	printf("Hash table:\n");
	for (int i = 0; i < D; i++) {
		printf("%d:", i);
		if (hash[i]) {
			printf("%s (%d)", hash[i], myHash(hash[i]));
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

	char** arr = (char**)calloc(D,sizeof(char*));
	char tmp[6];
	while (fscanf_s(in, "%s", tmp, sizeof(tmp)) > 0) {
		insert(arr, tmp, D);
	}

	printTable(arr, D);
	
}