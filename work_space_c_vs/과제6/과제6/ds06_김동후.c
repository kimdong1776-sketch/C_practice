#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int row;
	int col;
	int value;
} term;

term* get_transpose(term* A, term* B) {
	B =(term*)malloc(sizeof(term) * (A[0].value +1)); 
	int* startingPos = (int*)malloc(sizeof(int) * (A[0].col));
	int* rowTerms = (int*)malloc(sizeof(int) * (A[0].col));
	int i, j= 0;
	B[0].row = A[0].col;
	B[0].col = A[0].row;
	B[0].value = A[0].value;

	if (A[0].value > 0) {
		for (i = 0; i < A[0].col; i++) {
			rowTerms[i] = 0;
		}
		for (i = 1; i < A[0].value+1; i++) {
			rowTerms[A[i].col]++;
		}
		startingPos[0] = 1;
		for (i = 1; i < A[0].col;i++) {
			startingPos[i] = startingPos[i - 1] + rowTerms[i - 1];
		}
		for (i = 1; i < A[0].value+1; i++) {
			j = startingPos[A[i].col]++;
			B[j].row = A[i].col;
			B[j].col = A[i].row;
			B[j].value = A[i].value;
			printf("%d ", i);
		}

	}
	return B;
}
void print_tofile_transpose(FILE* out,term* A) {
	for (int i = 0; i < A[0].value+1; i++) {
		printf("a");
		fprintf(out,"%d ", A[i].row);
		fprintf(out, "%d ", A[i].col);
		fprintf(out, "%d \n", A[i].value);
	}
}
term* get_sparse_matrix(int** matrix, int rows, int cols, term* A) {
	
	int value_count = 0;
	int _idx=1;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (matrix[i][j] != 0)
				value_count++;
		}
	}

	A = (term*)malloc(sizeof(term) * (value_count + 1));
	A[0].row = rows;
	A[0].col = cols;
	A[0].value = value_count;

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (matrix[i][j] != 0) {
				A[_idx].row = i;
				A[_idx].col = j;
				A[_idx].value = matrix[i][j];
				_idx++;
			}
		}
	}
	return A;
}

void print_sparse_matrix(term* A) {
	for (int i = 0; i < A[0].value+1; i++) {
		printf("%d ", A[i].row);
		printf("%d ", A[i].col);
		printf("%d \n", A[i].value);
	}
}

void put_matrix(FILE* in,int **matrix, int rows, int cols) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			fscanf_s(in, "%d ", &matrix[i][j]);
		
		}
	}
}
void print_matrix(int** matrix, int rows, int cols) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
}

int main() {
	FILE *in, *out;
	term* A = NULL;
	term* B = NULL;
	fopen_s(&in, "in.txt", "r");
	fopen_s(&out, "out.txt", "w");
	int** matrix = NULL;
	int M, N;
	if (in == NULL || out == NULL) {
		fprintf(stderr, "file err\n");
		exit(1);
	}
	printf("컴퓨터학부 2025003170 김동후\n");
	fscanf_s(in,"%d %d\n", &M, &N);
	
	matrix = (int**)malloc(sizeof(int*) * M);
	for (int i = 0; i < M; i++) {
		matrix[i] = (int*)malloc(sizeof(int) * N);
	}
	put_matrix(in, matrix, M, N);
	fclose(in);
	

	print_matrix(matrix, M, N);

	A = get_sparse_matrix(matrix, M, N, A);
	print_sparse_matrix(A);

	B = get_transpose(A, B);
	print_tofile_transpose(out, B);



	free(matrix);
	free(A);
	free(B);
	
}