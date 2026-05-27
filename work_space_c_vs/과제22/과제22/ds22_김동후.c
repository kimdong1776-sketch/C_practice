#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int myHashFunc(char item[], int len) {
	int result = item[0];
	for (int i = 1; i < len; i++) {
		result += item[i];
	}
	return result;
}

void insert(char** hashTable, char* tmpArr, int len, int hash_size) {
	int i = 0;
	int hash_val = myHashFunc(tmpArr, len) % hash_size;

	for (; hashTable[(hash_val + i) % hash_size] != NULL; i++);

	int idx = (hash_val + i) % hash_size;

	hashTable[idx] = (char*)malloc(sizeof(char) * (len + 1));
	if (hashTable[idx]) {
		strcpy_s(hashTable[idx], len + 1, tmpArr);
	}
}

void printHsahTable(char* hashTable[], int size) {
	printf("Hash table:\n");
	for (int i = 0; i < size; i++) {
		printf("%d:", i);
		if (hashTable[i]) {
			printf(" %s (%d)", hashTable[i], myHashFunc(hashTable[i], strlen(hashTable[i])));
		}
		printf("\n");
	}
}

int searchKeys(char* sArr, char** hashTable, int hash_size) {
	for (int i = 0; i < hash_size; i++) {
		if (hashTable[i] != NULL && strcmp(hashTable[i], sArr) == 0) {
			return i;
		}
	}
	return -1;
}

void P1() {
	FILE* in, * s;
	char tmpArr[100];
	char** hashTable;
	fopen_s(&in, "in.txt", "r");
	fopen_s(&s, "search.txt", "r");
	if (!in || !s) {
		fprintf(stderr, "fileopenerr\n");
		exit(1);
	}

	int hash_size;
	printf("<scanf> ");
	scanf_s("%d", &hash_size);

	hashTable = (char**)calloc(hash_size, sizeof(char*));

	int len;

	
	while (fscanf_s(in, "%s", tmpArr, sizeof(tmpArr)) > 0) {
		len = strlen(tmpArr);
		insert(hashTable, tmpArr, len, hash_size);
	}

	printHsahTable(hashTable, hash_size);
	printf("\n");

	char sArr[100];
	
	while (fscanf_s(s, "%s", sArr, sizeof(sArr)) > 0) {
		printf("%s: %d\n", sArr, searchKeys(sArr, hashTable, hash_size));
	}
}

int main() {
	printf("학부:컴퓨터학부 학번:2025003170 이름:김동후\n");
	P1();
}