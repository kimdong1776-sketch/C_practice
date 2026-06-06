#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
	char str[6];      
	struct node* next;
} node;

int myHashFunc(char item[], int len) {
	int result = 0;
	for (int i = 0; i < len; i++) {
		result += item[i];
	}
	return result;
}

void insert(node** hashTable, char* tmpArr, int len, int hash_size) {
	int hash_val = myHashFunc(tmpArr, len) % hash_size;

	node* newNode = (node*)malloc(sizeof(node));
	strcpy_s(newNode->str, sizeof(newNode->str), tmpArr);

	// 맨 앞에 넣기 
	newNode->next = hashTable[hash_val];
	hashTable[hash_val] = newNode;
}

node* search(char* sArr, node* hashTable[], int hash_size) {
	int len = strlen(sArr);
	int hash_val = myHashFunc(sArr, len) % hash_size;

	node* current = hashTable[hash_val];
	while (current != NULL) {
		if (strcmp(current->str, sArr) == 0) {
			return current; 
		}
		current = current->next;
	}
	return NULL; // 못찾음
}

void printHashTable(node* hashTable[], int size) {
	printf("Hash table:");
	for (int i = 0; i < size; i++) {
		printf("\n%d:", i);
		node* current = hashTable[i];
		while (current != NULL) {
			printf(" %s (%d)", current->str, myHashFunc(current->str, strlen(current->str)));
			current = current->next;
		}
	}
}

void P1() {
	FILE* in = NULL, * s = NULL;
	char tmpArr[6];
	node** hashTable; 

	fopen_s(&in, "in.txt", "r");
	fopen_s(&s, "search.txt", "r");
	if (!in || !s) {
		fprintf(stderr, "fileopenerr\n");
		exit(1);
	}

	int hash_size;
	printf("<scanf> ");
	scanf_s("%d", &hash_size);

	
	hashTable = (node**)calloc(hash_size, sizeof(node*));

	int len;

	while (fscanf_s(in, "%s", tmpArr, sizeof(tmpArr)) > 0) {
		len = strlen(tmpArr);
		insert(hashTable, tmpArr, len, hash_size);
	}


	printHashTable(hashTable, hash_size);
	printf("\n");

	char sArr[100];
	
	while (fscanf_s(s, "%s", sArr,sizeof(sArr)) > 0) {
		node* result = search(sArr, hashTable, hash_size);
		if (result != NULL) {
			printf("%s: %d\n", sArr, myHashFunc(sArr, strlen(sArr)) % hash_size);
		}
		else {
			printf("%s: -1\n", sArr);
		}
	}

	
	fclose(in);
	fclose(s);
}

int main() {
	printf("학부:컴퓨터학부 학번:2025003170 이름:김동후\n");
	P1();
	return 0;
}