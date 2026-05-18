#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100
typedef struct element{
	int key;
	char data;
}element;

void SWAP(element* i, element* j) {
	element tmp = *i;
	*i = *j;
	*j = tmp;
}


void quickSort_key(element a[], int left, int right) {//오름차순
	int pivot, i, j;
	element temp;
	if (left < right) {
		i = left; j = right + 1;
		pivot = a[left].key;
		do {
			do i++; while (a[i].key < pivot);
			do j--; while (a[j].key > pivot);
			if (i < j)SWAP(&a[i], &a[j]);
		} while (i < j);
		SWAP(&a[left], &a[j]);
		quickSort_key(a, left, j - 1);
		quickSort_key(a, j+1, right);
	}
}

void quickSort_data(element a[], int left, int right) {//오름차순
	int pivot, i, j;
	element temp;
	if (left < right) {
		i = left; j = right + 1;
		pivot = a[left].data;
		do {
			do i++; while (a[i].data < pivot);
			do j--; while (a[j].data > pivot);
			if (i < j)SWAP(&a[i], &a[j]);
		} while (i < j);
		SWAP(&a[left], &a[j]);
		quickSort_data(a, left, j - 1);
		quickSort_data(a, j + 1, right);
	}
}
void print_a(element a[], int Lsize,int k) {
	for (int i = k; i < Lsize; i++) {
		printf("%d %c\n", a[i].key, a[i].data);
	}
}

void P1() {
	FILE* in;
	fopen_s(&in,"in.txt", "r");
	int tmp;
	char c;
	int Lsize = 0;
	while (fscanf_s(in, "%d ", &tmp)>0) {
		fscanf_s(in, "%c", &c, 1);
		Lsize++;
	}
	fseek(in, 0, SEEK_SET);
	element* a = (element*)malloc(sizeof(element) * (Lsize+1));
	a[Lsize].key = 2100000000;
	a[Lsize].data = 127;
	int i = 0;
	while (fscanf_s(in, "%d ", &tmp) > 0) {
		fscanf_s(in, "%c", &c, 1);
		a[i].key = tmp; a[i++].data = c;
	}

	int choice;
	printf("<scanf_s>");
	scanf_s("%d", &choice);
	if (choice == 1) { //key에대해
		quickSort_key(a, 0, Lsize-1);
	}
	else if (choice == 2) { //data에대해
		quickSort_data(a, 0, Lsize-1);
	}
	print_a(a, Lsize, 0);
}
// p2

void merge_key(element InitList[], element mergedList[], int i, int m, int n) {
	int j, k, t;
	j = m + 1;
	k = i;

	while (i <= m && j <= n) {
		if(InitList[i].key <= InitList[j].key) {
			mergedList[k++] = InitList[i++];
		}
		else {
			mergedList[k++] = InitList[j++];
		}
	}
	if (i > m) {
		for (t = j; t <= n;t++) {
			mergedList[t] = InitList[t];
		}
	}
	else {
		for (t = i; t <= m; t++) {
			mergedList[k + t - i] = InitList[t];
		}
	}
}

void merge_data(element InitList[], element mergedList[], int i, int m, int n) {
	int j, k, t;
	j = m + 1;
	k = i;

	while (i <= m && j <= n) {
		if (InitList[i].data <= InitList[j].data) {
			mergedList[k++] = InitList[i++];
		}
		else {
			mergedList[k++] = InitList[j++];
		}
	}
	if (i > m) {
		for (t = j; t <= n;t++) {
			mergedList[t] = InitList[t];
		}
	}
	else {
		for (t = i; t <= m; t++) {
			mergedList[k + t - i] = InitList[t];
		}
	}
}

void mergePass(element initList[], element mergedList[], int n, int s,int choice) {
	int i, j;
	for (i = 1; i < n - 2 * s + 1; i += 2 * s) {
		if(!choice){
			merge_key(initList, mergedList, i, i + s - 1, i + 2 * s - 1);
		}
		else {
			merge_data(initList, mergedList, i, i + s - 1, i + 2 * s - 1);
		}
	}
	if (i + s - 1 < n) {
		if (!choice) {
			merge_key(initList, mergedList, i, i + s - 1, n);
		}
		else {
			merge_data(initList, mergedList, i, i + s - 1, n);
		}
		
	}
	else {
		for (j = i; j <= n; j++) {
			mergedList[j] = initList[j];
		}
	}
}

void mergeSort(element a[], int n, int choice) {
	int k;
	if (choice == 1) {
		k = 0;
	}
	else
		k = 1;
	int s = 1;
	element extra[MAX_SIZE];

	while (s < n) {
		mergePass(a, extra, n, s, k);
		s *= 2;
		mergePass(extra, a, n, s,k);
		s *= 2;
	}
}

void P2() {
	FILE* in;
	fopen_s(&in, "in.txt", "r");
	int tmp;
	char c;
	int Lsize = 0;
	while (fscanf_s(in, "%d ", &tmp) > 0) {
		fscanf_s(in, "%c", &c, 1);
		Lsize++;
	}
	fseek(in, 0, SEEK_SET);
	element* a = (element*)malloc(sizeof(element) * (Lsize + 1));
	int i = 1;
	while (fscanf_s(in, "%d ", &tmp) > 0) {
		fscanf_s(in, "%c", &c, 1);
		a[i].key = tmp; a[i++].data = c;
	}
	fclose(in);
	int choice;
	printf("<scanf_s>");
	scanf_s("%d", &choice);

	mergeSort(a, Lsize,choice);
	//print_a못쓰네
	for (int i = 1; i <= Lsize; i++) printf("%d %c\n", a[i].key, a[i].data);
}
int main() {
	printf("학부:컴퓨터학부 학번:2025003170 이름:김동후\n");
	printf("문제 1:\n");
	P1();
	printf("문제 2:\n");
	P2();
}