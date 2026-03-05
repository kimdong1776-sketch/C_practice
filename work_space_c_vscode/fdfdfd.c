#include <stdio.h>
#include <stdlib.h>

int main() {
	printf("컴퓨터학부 2025003170 김동후\n");
	char* fname = "in.txt";
	int n;
	int num;
	FILE* f ;

	if ((f = fopen(fname, "r")) == NULL) {
		fprintf(stderr, "err");
		exit(1);
	}

	fscanf_s(f, "%d\n", &n);
	printf("단계 3 : %d", n);
	int* L = NULL;
	L = (int*)malloc(sizeof(int)* n);
	if (L == NULL) {
		fprintf(stderr, "err");
		exit(1);
	}
	printf("\n");


	int i = 0;
	printf("단계 6: ");
	while (fscanf_s(f, "%d", &num) != EOF) {
		L[i] = num;
		fprintf(stdout, "%d ", L[i]);
	}
	fclose(f);

	printf("\n");
	int temp = L[0];
	int j;
	for (j = 1; j < n; j++) {
		if (temp > L[j]) {
			temp = L[j];
		}
	}

	printf("단계 7: %d\n", temp);

	int temp1 = temp;
	for (int k = 1; k < n; k++) {
		if (k == j) {
			k++;
		}
		if (temp1 > L[k]) {
			temp1 = L[k];
		}
	}
	printf("단계 8: %d\n", temp1);

	printf("단계 9: ");
	for (int k = 0; k < n; k++) {
		for (int x = k; x < n; x++) {
			if (L[k] == L[x]) {
				printf("%d ", L[k]);
			}
		}
	}

}