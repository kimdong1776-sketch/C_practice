#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node* next;
}node;

node** aList;



void dfs(int v, int visited[]) {

	node* w;
	visited[v - 1] = 1;
	printf("%d ", v);
	for (w = aList[v - 1]; w; w = w->next) {
		if (!visited[(w->data) - 1]) {
			dfs(w->data, visited);
		}
	}
}



int main() {
	printf("¤·¤·\n");
	FILE* in;
	fopen_s(&in, "in.txt", "r");
	if (!in) {
		fprintf(stderr, "file open err\n");
		exit(1);
	}

	int vertex;
	fscanf_s(in, "%d", &vertex);
	int temp;

	int** arr = (int**)calloc(vertex, sizeof(int*));
	for (int i = 0; i < vertex;i++) {
		arr[i] = (int*)calloc(vertex, sizeof(int));
	}
	int verIdx = 1;
	for (int i = 1; i < vertex; i++) {
		for (int j = 0; j < i;j++) {
			fscanf_s(in, "%d", &temp);
			if (temp) {
				arr[i][j] = 1;
				arr[j][i] = 1;
			}
		}
	}

	aList = (node**)calloc(vertex, sizeof(node*));
	for (int i = 0; i < vertex;i++) {
		for (int j = vertex - 1; j >= 0; j--) {
			if (arr[i][j]) {
				node* tmp = (node*)malloc(sizeof(node));
				tmp->data = j + 1;
				tmp->next = aList[i];
				aList[i] = tmp;
			}
		}
	}

	for (int i = 0; i < vertex; i++) {
		printf("Vertex %d: ", i + 1);
		for (node* cur = aList[i];cur;cur = cur->next) {
			printf("%d ", cur->data);
		}
		printf("\n");
	}
	int* vistited = (int*)calloc(vertex, sizeof(int));

	while (1) {
		printf("scanf ÀÔ·Â: ");
		scanf_s("%d", &temp);
		if (temp < 0) {
			break;
		}
		for (int i = 0; i < vertex; i++) {
			vistited[i] = 0;
		}
		dfs(temp, vistited);
		printf("\n");
	}
	fclose(in);
}