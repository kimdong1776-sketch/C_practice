#include <stdio.h>
#include <stdlib.h>

int cmp(int a, int b) {
	if (a < b) {
		return 1;
	}
	if (a > b) {
		return -1;
	}
	if (a == b) {
		return 0;

	}
}

void push_to_arr(int* arr, int n, int idx) {
	arr[idx] = n;
}

int paa(int startA,int endA,int startb,int endB,int* a, int*b, int* arr) {
	int val = 0;
	int idx = 0;
	while (startA <= endA && startb <= endB) {
		switch(cmp(a[startA], b[startb])){
			case 1:
				push_to_arr(arr, a[startA], idx);
				startA++;
				idx++;
				break;
			case 0:
				push_to_arr(arr, a[startA], idx);
				startA++;
				startb++;
				idx++;
				break;
			case -1:
				push_to_arr(arr, b[startb], idx);
				startb++;
				idx++;
				break;
		}
	}
	for (;startA <= endA;startA++) {
		push_to_arr(arr, a[startA], idx);
		idx++;
	}
	for (;startb <= endB;startb++) {
		push_to_arr(arr, b[startb],idx);
		idx++;
	}
	return idx;
}

int main() {
	FILE* a = NULL;
	FILE* b = NULL;
	int* A, * B;
	int A_size;
	int B_size;
	int* arr;
	int arr_size = 0;
	fopen_s(&a, "a.txt", "r");
	fopen_s(&b, "b.txt", "r");

	if (a == NULL || b == NULL) {
		fprintf(stderr, "file open err\n");
		exit(1);
	}
	fprintf(stdout, "컴퓨터학부 2025003170 김동후\n");

	fscanf_s(a, "%d", &A_size);
	fscanf_s(b, "%d", &B_size);

	A = (int*)malloc(sizeof(int) * A_size);
	B = (int*)malloc(sizeof(int) * B_size);
	arr = (int*)malloc(sizeof(int) * (A_size+ B_size));

	for (int i = 0; i < A_size; i++) { //개수 세기
		fscanf_s(a,"%d",&A[i]);
	}
	for (int i = 0; i < B_size; i++) {
		fscanf_s(b,"%d",&B[i]);
	}

	arr_size = paa(0,A_size-1,0,B_size-1,A,B,arr);
	for (int i = 0; i < arr_size; i++) {
		printf("%d ", arr[i]);
	}
	free(A);
	free(B);
	free(arr);
	fclose(a);
	fclose(b);
}