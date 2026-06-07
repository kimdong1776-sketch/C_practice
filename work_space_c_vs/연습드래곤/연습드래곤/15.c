#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int num;
	char str[20];
}node;

node heap[20] = { 0 };

void pushH(node ptr, int *n) {
	int i = ++(*n);
	while (i != 1 && heap[i/2].num<ptr.num) {
		heap[i] = heap[i/2];
		i /= 2;
	}
	heap[i] = ptr;
}

node popH(int *n) {
	int parent = 1, child = 2;
	node re = heap[1];
	node tmp = heap[(*n)--];

	while (child <= *n) {
		if (child < *n && heap[child].num > heap[child + 1].num) {
			child++;
		}
		if (tmp.num < heap[child].num) break;
		heap[parent] = heap[child];
		parent = child;
		child *= 2;

	}
	heap[parent] = tmp;
	return re;
}