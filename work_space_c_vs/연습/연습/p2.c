#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

void IterationFibonacci(int n, int* arr) {
	arr[0] = 0; arr[1] = 1;

	for (int i = 2; i < n; i++) {
		arr[i] = arr[i - 1] + arr[i - 2];
	}
}

int RecursionFibonacci(int n, int* arr) {
	if (n <= 1) {
		return n;
	}
	return (RecursionFibonacci(n-1, arr) + RecursionFibonacci(n-2, arr));
}


int main() {
	clock_t start, finish;
	double elapsed;

	while (1) {
		int n;
		scanf_s("%d", &n);
		int* arr = (int*)malloc((sizeof(int) * n) + 1);
		if (n < 0 || n >45) break;
		start = clock();
		IterationFibonacci(n, arr);
		finish = clock();
		free(arr);
		elapsed = ((double)(finish)-(double)(start)) / CLOCKS_PER_SEC;
		printf("time: %f\n", elapsed * 1000.0);



		//--------------------------------------------
		scanf_s("%d", &n);
		arr = (int*)malloc((sizeof(int) * n) + 1);
		if (n < 0 || n >45) break;
		start = clock();
		RecursionFibonacci(n, arr);
		finish = clock();
		free(arr);
		elapsed = ((double)(finish)-(double)(start)) / CLOCKS_PER_SEC;
		printf("time: %f\n", elapsed * 1000.0);
	}
	

	return 0;
}