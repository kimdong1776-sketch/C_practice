#include <stdio.h>
#include <stdlib.h>
typedef struct node {
	int data;
	struct node* next;
}node;

node** aList;
node* qfirst = NULL;
node* qrear = NULL;


void addq(int i) {
	
	node* temp = (node*)malloc(sizeof(node));
	temp->data = i; temp->next = NULL;
	if (qfirst) {
		qrear->next = temp;
	}
	else {
		qfirst = temp;
	}
	qrear = temp;
}

int deleteq() {
	if (!qfirst) {
		fprintf(stderr, "queue is empty\n");
		exit(1);
	}
	node* item = qfirst;
	qfirst = qfirst->next;
	return (item->data);
}

void bfs(int v, int* visited, int show_print) {
	node* w;
	qfirst = qrear = NULL;

	if (show_print) {
		printf("%d ", v);
	}
	visited[v - 1] = 1;
	addq(v);

	while (qfirst) {
		v = deleteq();
		for (w = aList[v - 1]; w; w = w->next) {
			if (!visited[w->data - 1]) {
				if (show_print) {
					printf("%d ", w->data);
				}
				addq(w->data);
				visited[(w->data) - 1] = 1;
			}
		}
	}
}




void P1() {
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
	for (int i = 0; i < vertex; i++) {
		for (int j = vertex - 1; j >= 0; j--) {
			if (arr[i][j]) {
				node* tmp = (node*)malloc(sizeof(node));
				tmp->data = j + 1;
				tmp->next = aList[i];
				aList[i] = tmp;
			}
		}
	}

	int* vistited = (int*)calloc(vertex, sizeof(int));
	while (1) {
		printf("scanf 입력: ");
		scanf_s("%d", &temp);
		if (temp < 0) {
			break;
		}
		for (int i = 0; i < vertex; i++) {
			vistited[i] = 0;
		}
		bfs(temp, vistited, 1);
		printf("\n");
	}
}

int getComponentCount(int vertex, int* visited) {
	int count = 0;
	qfirst = qrear = NULL;


	for (int i = 0; i < vertex; i++) {
		visited[i] = 0;
	}

	for (int i = 0; i < vertex; i++) {
		if (!visited[i]) {
			count++;

			
			bfs(i + 1, visited, 0);
		}
	}
	return count;
}

void P2() {
	FILE* in;
	fopen_s(&in, "in.txt", "r");
	if (!in) {
		fprintf(stderr, "file open err\n");
		exit(1);
	}
	int vertex;
	fscanf_s(in, "%d", &vertex);

	int* visited = (int*)calloc(vertex, sizeof(int));

	printf("\nconnected component: %d 개\n", getComponentCount(vertex, visited));

	free(visited);
	fclose(in);
}

int main() {
	printf("학부:컴퓨터학부 학번:2025003170 이름:김동후\n");
	printf("문제 1:\n");
	P1();
	printf("문제 2:\n");
	P2();

}
