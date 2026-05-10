#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define MAX_ELEMENT 200

typedef struct element {
	int prec;
	char string[30];
}element;

element heap[MAX_ELEMENT];


void push(element item, int* n) {
	int i;
	if (*n >= MAX_ELEMENT - 1) {
		fprintf(stderr, "heap is full\n");
		exit(1);
	}

	i = ++(*n);
	while ((i != 1) && (item.prec < heap[i / 2].prec)) {
		heap[i] = heap[i / 2];
		i /= 2;
	}
	heap[i] = item;
}

element pop(int* n) {

	int parent, child;
	element item, temp;
	if (!(*n)) {
		fprintf(stderr, "heap is empty\n");
		exit(1);
	}
	item = heap[1];
	temp = heap[(*n)--];
	parent = 1;
	child = 2;
	while (child <= *n) {//재구성
		if (child < *n && heap[child].prec > heap[child + 1].prec) {
			child++;
		}
		if (temp.prec <= heap[child].prec) break;
		heap[parent] = heap[child];
		parent = child;
		child *= 2;
	}
	heap[parent] = temp;
	return item;
}

int main() {
	printf("학부:컴퓨터학부 학번:2025003170 이름:김동후\n");
	FILE* in;
	fopen_s(&in, "in.txt", "r");
	if (!in) {
		fprintf(stderr, "file open err\n");
		exit(1);
	}
	int tempN;
	char tempS[30];
	char c;
	element temp;
	int n = 0;
	while (fscanf_s(in, "%d %d", &tempN) > 0) {
		fgets(tempS, sizeof(tempS), in);
		if (tempS[strlen(tempS) - 1] == '\n') {
			tempS[strlen(tempS) - 1] = '\0';
		}

		temp.prec = tempN;
		strcpy_s(temp.string, sizeof(temp.string), tempS);
		push(temp, &n);
	}
	int count = n;
	for (int i = 0; i < count; i++) {
		temp = pop(&n);
		tempN = temp.prec; strcpy_s(tempS, sizeof(tempS), temp.string);
		printf("%d %s\n", tempN, tempS);
	}
}