#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int row;
	int col;
	int data;
}matrix;

matrix* get_3tuple_matrix(int **M, int row, int col, int v) {
	matrix* temp = (matrix*)malloc(sizeof(matrix) * (v+1));
	temp[0].row = row; temp[0].col = col; temp[0].data = v;
	int idx = 1;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (M[i][j]) {
				temp[idx].col = j; temp[idx].row = i; temp[idx].data = M[i][j];
				idx++;
			}
		}
	}
	return temp;
}

matrix* get_transpose_matrix(matrix * A){
	int* startingPos = (int*)malloc(sizeof(int) * (A[0].col));
	int* rowTerms = (int*)malloc(sizeof(int) * (A[0].col));
	startingPos[0] = 1;
	matrix* B = (matrix*)malloc(sizeof(matrix)*(A[0].data+1));
	for (int i = 0; i < A[0].col; i++) {
		rowTerms[i] = 0;
	}
	for (int i = 1; i <= A[0].data; i++) {
		rowTerms[A[i].col]++;
	}
	for (int i = 1; i <= A[0].col; i++) {
		startingPos[i] = rowTerms[i - 1] + startingPos[i - 1];
	}
	int j = 0;
	B[0].col = A[0].row;B[0].row = A[0].col;B[0].data = A[0].data;
	for (int i = 1; i <= A[0].data; i++) {
		j = startingPos[A[i].col]++;
		B[j].data = A[i].data; B[j].col = A[i].row; B[j].row = A[i].col;
	}
	return B;
}

int main() {
	FILE* in;
	fopen_s(&in, "in.txt", "r");
	if (!in) {
		exit(1);
	}
	int m, n;
	int** M;
	int count = 0;
	fscanf_s(in, "%d %d", &m, &n);
	 M = (int**)malloc(sizeof(int *)*m);
	for (int i = 0; i < m; i++) {
		M[i] = (int*)malloc(sizeof(int) * n);
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			fscanf_s(in ,"%d", &(M[i][j]));
			
		}
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", M[i][j]);
			if (M[i][j]) {
				count++;
			}
		}
		printf("\n");
	}

	matrix* A;
	A = get_3tuple_matrix(M, m, n,count);
	for (int i = 0; i < count+1; i++) {
		
		printf("%d %d %d \n", A[i].row, A[i].col, A[i].data);
	}
	matrix* B;
	B = get_transpose_matrix(A);
	printf("B>>\n");
	for (int i = 0; i < count+1; i++) {
		printf("%d %d %d \n", B[i].row, B[i].col, B[i].data);
	}
}