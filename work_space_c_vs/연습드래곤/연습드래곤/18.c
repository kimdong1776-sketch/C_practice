#include <stdio.h>
#include <stdlib.h>

typedef struct element {
	int w, x, y;
}element;

void insert(element e, element a[], int i) {
	a[0] = e;
	int j;
	for (j = i;e.w < a[j].w;j--) {
		a[j + 1] = a[j];
	}
	a[j + 1]= e;
}

void insertionSort(element a[], int n) {
	for (int j = 2; j <= n; j++) {
		insert(a[j], a, j-1);
	}
}

int main() {
	FILE* in;
	fopen_s(&in, "in.txt", "r");
	if (!in) return;

	int max_edge, n;
	int tmp;
	fscanf_s(in,"%d", &n);
	max_edge = (n * (n - 1)) / 2;
	element* edge = (element*)malloc(sizeof(element)*(max_edge+1));
	int k = 1;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			fscanf_s(in, "%d", &tmp);
			if (tmp) {
				edge[k].w = tmp;
				
				edge[k].x = i+1;
				edge[k++].y = j+1;
			}
		}
	}

	insertionSort(edge, k-1);

	for (int i = 1; i <= k-1;i++) {
		printf("%d (%d, %d)\n", edge[i].w, edge[i].x, edge[i].y);
	}

}