#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {

	FILE* f = fopen("in.txt", "r");
	if (f == NULL) {
		fprintf(stderr, "file open err");
		exit(1);
	}
	printf("컴퓨터학부 2025003170 김동후\n");
	int n = 0;
	int count = 0;
	while ((fscanf_s(f, "%d", &n)) != EOF) {
		count++;
	}
	printf("N: %d\n", count);

	int* L = NULL;
	L = (int*)malloc(sizeof(int) * count);
	rewind(f);
	for (int i = 0; i < count; i++) {
		fscanf_s(f, "%d", L + i);
		printf("%d ", *(L + i));
	}
	fclose(f);

	while (1) {
		int k;
		int search_num = 0;
		int* T = (int*)malloc(sizeof(int) * count);
		printf("(scanf) ");
		scanf_s("%d", &k);
		if (!(k > 0)) {
			break;
		}

		

		for (int i = 0; i < count; i++) {
			if (L[i] == k) {
				L[i] = -1;
				search_num++;
			}
		}
		
		int t = 0;
		int write_idx = 0;
		for (int read_idx = 0; read_idx < count; read_idx++) {
			if (L[read_idx] != -1) {
				T[write_idx] = L[read_idx];
				write_idx++;
			}
		}

		count -= search_num;


		if (count == 0) {
			printf("L is empty\n");
			free(T);
			break;
		}
		memcpy(L, T, sizeof(int)*count);
		L = (int*)realloc(L, sizeof(int) * count);
		for (int i = 0; i < count; i++) {
			printf("%d ", *(L + i));
		}
		free(T);
		printf("\n");
	}
	free(L);
	return 0;
}