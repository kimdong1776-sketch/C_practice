#include <stdlib.h> 
#include <stdio.h> 
#include <time.h> 
#include <string.h>
void fibonacci_Iterative(int *arr, int n) {
	arr[0] = 0;
	if (n != 1) {
		arr[1] = 1;

	}
	for (int i = 2; i < n;i++) {
		arr[i] = arr[i - 1] + arr[i - 2];
	}
}
int fibonacci_Recursive(int n) {
	if (n <= 1) {
		return n;
	}

	return (fibonacci_Recursive(n - 1) + fibonacci_Recursive(n - 2));
	

}


int main() {  
	printf("컴퓨터학부 2025003170 김동후\n");

	int* arr = NULL;
	int n = 0;

	clock_t start, finish;
	double elapsed;

	while (1){
		printf("(scanf_s) ");
		scanf_s("%d", &n);
		if (n == -1) {
			break;
		}
		arr = (int*)malloc((sizeof(int) * (n+1)));
		start = clock();
		fibonacci_Iterative(arr, n +1 );
		printf("Iterative: %d", arr[n]);
		finish = clock();
		elapsed = ((double)(finish)-(double)(start)) / CLOCKS_PER_SEC;
		printf("(%f ms)\n", elapsed * 1000.0);
		free(arr);
		//
		//arr = (int*)malloc((sizeof(int) * (n+1)));
		start = clock();
		int d = fibonacci_Recursive(n);
		printf("Recursive: %d", d);
		finish = clock();
		elapsed = ((double)(finish)-(double)(start)) / CLOCKS_PER_SEC;
		printf("(%f ms)\n", elapsed * 1000.0);
		//free(arr);

	}
	
	
	return 0;
	
	
	
	
} 