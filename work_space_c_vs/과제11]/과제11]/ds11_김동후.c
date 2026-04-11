#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

typedef struct node {
	int data;
	struct node* next;
}node;

node* srs[MAX_SIZE] = { 0 };

int main() {
	printf("컴퓨터학부 2025003170 김동후\n");
	FILE* in;
	fopen_s(&in, "in.txt", "r");
	if (!in) {
		fprintf(stderr, "file open err");
		exit(1);
	}
	short out[MAX_SIZE];
	node* x, *y, *top;
	int n;
	int a, b;
	fscanf_s(in,"%d", &n);
	for (int i = 0;i < n; i++) {
		out[i] = 1;
	}
	fscanf_s(in, "%d %d", &a, &b);
	while (a > 0 || b > 0) {
		
		x = (node*)malloc(sizeof(node));
		x->data = b;
		x->next = srs[a]; 
		srs[a] = x;
		x = (node*)malloc(sizeof(node));
		x->data = a;
		x->next = srs[b];
		srs[b] = x;
		fscanf_s(in, "%d %d", &a, &b);
	}
	
	for (int i = 0; i < n; i++) {
		printf("%d: ", i);
		node* cur = srs[i];
		while (cur != NULL) {
			printf("%d ", cur->data);
			cur = cur->next;
		}
		printf("\n");
	}
	int j = 0;
	for (int i = 0; i < n; i++) {
		int flag = 0; // {}출력관련 flag
		printf("{");
		if (out[i]) { //처음에 i가 출력이 안 됐다면
			flag = 1;
			printf("%d ", i);
			out[i] = 0;
		}
		x = srs[i]; top = NULL;
		for (;;) {
			while (x) {
				j = x->data;
				if (out[j]) { // j가 출력이 안 됐다면
					printf("%d ",j);
					flag = 1;
					out[j] = 0;

					y = x->next;
					x->next = top;
					top = x;
					x = y;
				}
				else
					x = x->next; 
			}
			if (!top) {
				printf("\b");
				break;
			}
			x = srs[top->data]; 
			top = top->next;
		}
		if (flag) {
			printf("}\n");
			flag = 0;
		}
		
		
	}

}