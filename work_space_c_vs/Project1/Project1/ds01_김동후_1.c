#include <stdio.h>
#include <stdlib.h>

int main() {
	printf("컴퓨터학부 2025003170 김동후\n");
	char* fname = "in.txt";
	int n;
	int num;
	int* jung = NULL;
	
	FILE* f = NULL;
	(fopen_s(&f, fname, "r"));
	

	fscanf_s(f, "%d\n", &n);
	printf("단계 3: %d", n);
	int* L = NULL;
	L = (int*)malloc(sizeof(int) * n);
	jung = (int*)malloc(sizeof(int) * n);
	for (int e = 0; e < n; e++) {
		jung[e] = 0;
	}
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
		i++;
	}
	fclose(f);

	printf("\n");
	int temp = *L;
	int j;
	for (j = 1; j < n; j++) {
		if (temp > *(L + j)) {
			temp = *(L + j);
		}
	}

	printf("단계 7: %d\n", temp);

	int temp1 = L[0];
	int k ;
	for (int y = 1; y < n; y++) {
		if (temp1 == temp) {
			temp1 = L[y];
		}

	}
	for (k = 1; k < n; k++) {
		if (temp == *(L + k)) {
			k++;
			continue;
		}
		if (temp1 > *(L + k)) {
			temp1 = *(L + k);
		}
	}
	printf("단계 8: %d\n", temp1);
	int plag = 0;
	int d = 0;
	printf("단계 9: ");
	for (int v = 0; v < n-1; v++) {
		for (int x = v+1; x < n; x++) {
			if (L[v] == L[x]) {
				d = 1;
				for (int q = 0; q < n; q++) { //중복 중복 검사
					if (L[v] == jung[q]) {
						plag = 1;
						break;
					}
				}
				if (plag == 0) {
					printf("%d ", L[v]);
					jung[v] = L[v];//중복 카운트
				}
				plag = 0;
				
			}		
		}
	}
	if (d == 0) {
		printf("중복 없음");
	}
	

}