#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100
typedef struct element {
	int key;
	char data;
}element;

void swap(element* a, element* b) {
	element t = *a;
	*a = *b;
	*b = t;
}

void quickSort(element a[], int left, int right) {
	int i = left, j = right + 1;
	if (left < right) {
		int pivot = a[left].data;
		do {
			do { i++; } while (a[i].data < pivot);
			do { j--; } while (a[j].data > pivot);
			if (i < j) swap(&a[j], &a[i]);
		} while (i < j);
		swap(&a[left],&a[j]);
		quickSort(a,left, j-1);
		quickSort(a, j +1,right );
	}
}

void myprint(element* arr, int len) {
	for (int i = 0; i < len - 1; i++) {
		printf("%d %c\n", arr[i].key, arr[i].data);
	}
}

void P1() {
	FILE* in;
	fopen_s(&in, "in.txt", "r");


	int n; char c;
	int len = 0;
	while (fscanf_s(in,"%d", &n)>0) {
		fscanf_s(in, " %c", &c, 1);
		len++;
	}
	fseek(in, 0, SEEK_SET);
	len++;
	element* arr = (element*)malloc(sizeof(element)*len);
	for (int i = 0; i < len-1; i++) {
		fscanf_s(in, "%d", &n);	fscanf_s(in, " %c", &c,1);
		arr[i].data = c; arr[i].key = n;
	}
	arr[len - 1].key = 2100000000;
	arr[len - 1].data = 127;
	quickSort(arr, 0, len-1);

	myprint(arr, len);
}
//---

void merge(element e[], element dire[], int i, int m, int n) {
	int j = m + 1;
	int k = i;
	while (i <=m && j <= n) {
		if (e[i].data <= e[j].data) {
			dire[k++] = e[i++];
		}
		else {
			dire[k++] = e[j++];
		}
	}
	if (i > m) {
		for (int t = k; j <= n; t++) {

			dire[t] = e[j++];
		}
	}
	else {
		for (int t = k; i <= m; t++) {
			dire[t] = e[i++];
		}
	}
}

void mergePass(element e[],element m[], int s, int n) {
	int i;
	for (i = 1; i + 2*s -1 <= n; i += 2*s) {
		merge(e, m, i, i+s-1,i+2*s-1);
	}
	if (i+s-1 < n) {
		merge(e, m, i, i + s - 1, n);
	}
	else {
		for (int j = i; j <= n;j++) {
			m[j] = e[j];
		}
	}
}

void mergesort(element e[], element m[], int n) {
	int s = 1;
	while (s < n) {
		mergePass(e, m, s, n);
		s *= 2;
		mergePass(m, e, s, n);
		s *= 2;
	}

}
int main() {
	P1();
}