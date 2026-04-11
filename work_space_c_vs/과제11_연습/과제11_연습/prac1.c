#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node* next;
}node;

int main() {
	FILE* in;
	fopen_s(&in, "in.txt", "r");
	int n;
	fscanf_s(in, "%d", &n);
	node* first = 0, *end = 0;
	int i = 1;
	while (n != i) {
		

		node* x = (node*)malloc(sizeof(node));
		
		x->data = n / i;
		i *= 2;
		x->next = NULL;
		if (!first) {
			first = x;
			end = x;
		}
		else {
			end->next = x;
			end = x;
		}
		
		

	}
	node* x = (node*)malloc(sizeof(node));

	x->data = n / i;
	i *= 2;
	x->next = NULL;

	
	end->next = x;
	end = x;

	for (node* cur = first; cur != NULL; cur = cur->next) {
		printf("%d(%u)\n", cur->data, cur);
	}
}