#include <stdio.h>
#include <stdlib.h>


typedef struct node {
	struct node* next;
	int data;
}node;

node** alist;
int visited[20];

void dfs(int v) {
	printf("%d", v);
	visited[v] = 1;
	for (node* w = alist[v]; w; w= w->next) {
		if (!visited[w->data]) {
			dfs(w->data);
		}
	}
}

void P1() {
	FILE* in;
	fopen_s(&in, "in.txt", "r");

	int n;
	fscanf_s(in,"%d", &n);
	int** matrix = (int**)malloc(sizeof(int*)*n);
	for (int i = 0; i < n; i++) {
		matrix[i] = (int*)calloc(n, sizeof(int));
	}
	int tmp;
	for (int i = 1; i < n;i++) {
		for (int j = 0; j < i; j++) {
			fscanf_s(in, "%d", &tmp);
			if (tmp) {
				matrix[i][j] = 1;
				matrix[j][i] = 1;
			}
		}
	}


	alist = (node**)calloc(n+1, sizeof(node*));
	for (int i = 0; i < n;i++) {
		for (int j = n-1; j>=0; j--) {
			if (matrix[i][j]) {
				node* newnode = (node*)malloc(sizeof(node));
				newnode->data = j+1; newnode->next = NULL;
				if (!alist[i+1]) {
					alist[i+1] = newnode;
				}
				else {
					newnode->next = alist[i+1];
					alist[i+1] = newnode;
				}
			}
		}
	}

	for (int i = 1; i <= n;i++) {
		printf("Vertex %d:", i);
		for (node* cur = alist[i]; cur; cur= cur->next) {
			printf(" %d", cur->data);
		}
		printf("\n");
	}


	while (1) {
		printf("scanf입력: ");
		scanf_s("%d", &tmp);
		if (tmp == -1) break;
		for (int i = 0; i <= n;i++) {
			visited[i] = 0;
		}
		dfs(tmp);
	}
}

int main() {
	P1();
}
