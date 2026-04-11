#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int coef;//계수
	int expon; //차수
} polynomial;

int COMPARE(int a, int b) {
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

void print_result(FILE* c,int size,polynomial* arr)
{

	for (int i = 0; i < size;i++) {
		fprintf(c,"%d ", arr[i].coef);
		fprintf(c, "%d ", arr[i].expon);
	}
}

void push_arr(int coefficient, int exponent, polynomial* arr,int idx) {
	arr[idx].coef = coefficient;
	arr[idx].expon = exponent;
}

int padd(int startA, int finishA, int startB, int finishB, polynomial* A, polynomial* B, polynomial* arr,FILE* c) {
	int N = 0;
	int coefficient;
	while (startA <= finishA && startB <= finishB)
		switch (COMPARE(A[startA].expon, B[startB].expon)) {
		case -1:
			push_arr(B[startB].coef, B[startB].expon, arr, N); // N에다가 b를 적어라
			startB++;
			N++;
			break;
		case 0:
			coefficient = A[startA].coef + B[startB].coef;
			if (coefficient)// 0이아니면
			{
				push_arr(coefficient, A[startA].expon, arr, N);
				N++;
			}
			startA++;
			startB++;
			
			break;
		case 1:
			push_arr(A[startA].coef, A[startA].expon, arr,N); //a를 적어라
			startA++;
			N++;
			break;
		}
	
	for (; startA <= finishA; startA++) {
		push_arr(A[startA].coef, A[startA].expon, arr,N);
		N++;
	}
	
	for (; startB <= finishB; startB++) {
		push_arr(B[startB].coef, B[startB].expon, arr,N);
		N++;
	}
	return N;

}

int main() {
	FILE* a = NULL;
	FILE* b = NULL;
	FILE* c = NULL;
	polynomial* A = NULL;
	polynomial* B = NULL;
	//polynomial* C = NULL;
	int A_size;
	int B_size;
	int C_size;
	polynomial *arr = NULL;
	fopen_s(&a, "a.txt", "r");
	fopen_s(&b, "b.txt", "r");
	fopen_s(&c, "c.txt", "w");

	if (a == NULL || b == NULL || c == NULL) {
		exit(1);
		fprintf(stderr, "file open err\n");
	}
	fprintf(c, "컴퓨터학부 2025003170 김동후\n");
	fscanf_s(a, "%d\n", &A_size);
	fscanf_s(b, "%d\n", &B_size);

	C_size = A_size + B_size;
	A = (polynomial*)malloc(sizeof(polynomial) * A_size);
	B = (polynomial*)malloc(sizeof(polynomial) * B_size);
	arr = (polynomial*)malloc(sizeof(polynomial) * C_size);
	for (int i = 0; i < A_size;i++) {
		fscanf_s(a, "%d", &(A[i].coef));
		fscanf_s(a, "%d", &(A[i].expon));
	}
	for (int i = 0; i < B_size;i++) {
		fscanf_s(b, "%d", &(B[i].coef));	
		fscanf_s(b, "%d", &(B[i].expon));
	}
	//for (int i = 0; i < A_size;i++) {
	//	printf("testA(%d)\n", A[i].coef);
	//	printf("testA(%d)\n", A[i].expon);
	//}
	//for (int i = 0; i < B_size;i++) {
	//	printf("testA(%d)\n", B[i].coef);
	//	printf("testA(%d)\n", B[i].expon);
	//}

	
	C_size = padd(0, A_size - 1, 0, B_size-1, A, B, arr,c);
	fprintf(c, "%d\n", C_size);
	print_result(c, C_size, arr);

	fclose(a);
	fclose(b);
	fclose(c);

	free(A);
	free(B);
	free(arr);
}