#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node* next;
}node;

node* front, * rear;
int n;
void addq(int v) {
	node* tmp = (node*)malloc(sizeof(node));
	tmp->data = v;
	tmp->next = NULL;
	if (!front) {
		front = tmp;
	}
	else {
		rear->next = tmp;
	}
	rear = tmp;
}

int deleteq() {
	if (!front) {
		return NULL;
	}
	int tmp = front->data;
	node* d = front;
	front = front->next;
	free(d);
	return tmp;
}

node** aList;
int visit[100];

bfs(int v) {
	int tmp;
	rear = front = NULL;
	printf("%d", v);
	addq(v);
	visit[v] = 1;
	while (front) {
		tmp = deleteq();
		for (node* w = aList[tmp]; w; w = w->next) {
			if (!visit[w->data]) {
				printf("%d", w->data);
				addq(w->data);
				visit[w->data] = 1;
				}
		}
	}
}

void P1() {
	FILE* in;
	fopen_s(&in, "in.txt", "r");
	if (!in) {
		exit(1);
	}

	int tmp;
	fscanf_s(in, "%d", &n);
	int** matrix = (int**)malloc(sizeof(int*)*n);
	for (int i = 0; i< n;i++) {
		matrix[i] = (int*)calloc(n,sizeof(int));
	}
	for (int i = 1; i < n;i++) {
		for (int j = 0; j < i; j++) {
			fscanf_s(in, "%d", &tmp);
			if (tmp) {
				matrix[i][j] = 1;
				matrix[j][i] = 1;
			}
		}
	}
	aList = (node**)calloc(n+1, sizeof(node*));
	for (int i = 0; i < n;i++) {
		for (int j = n-1; j >= 0; j--) {
			if (matrix[i][j]) {
				node* newnode = (node*)malloc(sizeof(node));
				newnode->data = j + 1; newnode->next = NULL;
				if (!aList[i+1]) {
					aList[i+1] = newnode;
				}
				else {
					newnode->next = aList[i+1];
					aList[i+1] = newnode;
				}
			}
		}
	}
	while (1) {
		printf("dd");
		scanf_s("%d", &tmp);
		for (int i = 1; i <= n; i++) {
			visit[i] = 0;
		}
		if (tmp < 0) break;
		bfs(tmp);
	}
}

int count_componot() {
	for (int i = 1; i <= n; i++) {
		visit[i] = 0;
	}
	
	int count = 0;
	for (int i = 1; i <= n; i++) {
		if (!visit[i]) {
			bfs(i);
			count++;
		}
	}
	return count;
}

int main() {
	P1();
	P2();
}