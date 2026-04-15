#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int COMPARE(int a, int b) {
	if (a > b) {
		return 1;
	}
	else if (a < b) {
		return -1;
	}
	else
		return 0;
}

int seqsearch(int *arr , int snum, int s) {
	for (int i = 0; i < s; i++) {
		if (arr[i] == snum) {
			return i;
		}
	}
	return -1;
}

int search_i(int s, int f, int * arr, int snum) {
	int middle;
	while (s <= f) {
		middle = (s + f) / 2;
		switch (COMPARE(arr[middle], snum)) {
			case(1): // 미들이 크면
				f = middle - 1;
				break;
			case(0):
				return middle;
				break;
			case(-1): // 미들이 작으면
				s = middle + 1;
				break;
			}
	}
	return -1;
	
}

int search_r(int s, int f, int* arr, int snum) {
	int middle;
	if (s <= f) {
		middle = (s + f) / 2;
		switch (COMPARE(arr[middle], snum)) {
			case(1):
				search_r(s, middle-1, arr, snum);
				break;
			case(0):
				return middle;
				break;
			case(-1): 
				search_r(middle + 1, f, arr, snum);
				break;
		}
	}
	return -1;
}

int main() {
	printf("컴퓨터학부 2025003170 김동후\n");
	int L_size = 0;
	int temp;
	int* L = NULL;
	FILE* f = fopen("in.txt", "r");
	if (f == NULL) {
		fprintf(stderr, "file open err");
		exit(1);
	}

	while (!feof(f)) {
		L_size++;
		fscanf_s(f, "%d", &temp);
	}

	fseek(f, 0, SEEK_SET);

	L = (int*)malloc(L_size * sizeof(int));
	for (int i = 0; i < L_size; i++) {
		fscanf_s(f, "%d", &temp);
		L[i] = temp;
	}

	fclose(f);
	//단게2
	int freq = 100000;
	clock_t start, end;
	printf("sequential search:\n");
	start = clock();
	for (int i = 0; i < freq; i++) {
		int res = seqsearch(L, i, L_size);
		if (i < 5) printf("search %d result: %d\n", i, res);
	}
	end = clock();
	printf("computation time: %fms\n\n", 1000 * ((double)end - (double)start) / CLOCKS_PER_SEC);


	printf("iterative binary search:\n");
	start = clock();
	for (int i = 0; i < freq; i++) {
		int res = search_i(0, L_size, L, i);
		if (i < 5) printf("search %d result: %d\n", i, res);
	}
	end = clock();
	printf("computation time: %fms\n\n", 1000 * ((double)end - (double)start) / CLOCKS_PER_SEC);
	// 위의 코드를 참고하여 작성 
	printf("recursive binary search:\n");
	// 위의 코드를 참고하여 작성 
	start = clock();
	for (int i = 0; i < freq; i++) {
		int res = search_r(0, L_size, L, i);
		if (i < 5) printf("search %d result: %d\n", i, res);
	}
	end = clock();
	printf("computation time: %fms\n\n", 1000 * ((double)end - (double)start) / CLOCKS_PER_SEC);
	return 0;
}