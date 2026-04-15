#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

int compare(int a, int b) {
	if (a > b) {
		return 1;
	}
	else if (a < b) {
		return -1;
	}
	else {
		return 0;
	}
}

int sequential_search(int *arr, int arr_size, int search_num){
	for (int i = 0; i < arr_size; i++) {
		if (arr[i] == search_num) {
			return i;
		}
	}
	return -1;
}

int iterative_search(int* arr, int search_num,int left, int right) {
	int middle;
	while(left <= right) {
		middle = (left + right) / 2;
		switch (compare(arr[middle], search_num)) {
		case -1 : //가운데랑 찾고자하는 거랑 비교했을때 가운데가 작음
			left = middle + 1;
			break;
		case 0 : //같음
			return middle;
		case 1 : //큼
			right = middle - 1;
		}
	}
	return -1;
}

int recursive_search(int* arr, int search_num, int left, int right) {
	int middle;
	if (left <= right) {
		middle = (left + right) / 2;
		switch (compare(arr[middle], search_num)) {
		case -1: //가운데랑 찾고자하는 거랑 비교했을때 가운데가 작음
			return recursive_search(arr, search_num, middle + 1, right);
		case 0: //같음
			return middle;
		case 1: //큼
			return recursive_search(arr, search_num, left, middle -1);
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

	while(!feof(f)) {
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
	//------------------------------------
	printf("sequential search: \n");

	start = clock();

	for (int i = 0; i < freq; i++) {
		int res = sequential_search(L, L_size, i);
		if (i < 5) printf("search %d result: %d\n", i, res);
	}
	end = clock();
	
	printf("computation time: %fms\n\n", 1000 * ((double)end - (double)start) / CLOCKS_PER_SEC);
	//------------------------------------
	printf("iterative binary search:\n");
	start = clock();
	for (int i = 0; i < freq; i++) {
		int res = iterative_search(L, i, 0, L_size-1);
		if (i < 5) printf("search %d result: %d\n", i, res);
	}
	end = clock();
	printf("computation time: %fms\n\n", 1000 * ((double)end - (double)start) / CLOCKS_PER_SEC);
	// 위의 코드를 참고하여 작성 
	//------------------------------------
	printf("recursive binary search:\n");
	start = clock();
	for (int i = 0; i < freq; i++) {
		int res = recursive_search(L, i, 0, L_size-1);
		if (i < 5) printf("search %d result: %d\n", i, res);
	}
	end = clock();
	printf("computation time: %fms\n\n", 1000 * ((double)end - (double)start) / CLOCKS_PER_SEC);
	// 위의 코드를 참고하여 작성 

	free(L);
	return 0;
}