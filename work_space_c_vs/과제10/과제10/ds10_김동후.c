#include <stdio.h>
#include <stdlib.h>


typedef struct node {
	int coef;
	int exp;
	struct node * next;
}node;

int erase(node **ptr){
	node* temp;
	while (*ptr) {
		temp = *ptr;
		*ptr = (*ptr)->next;
		free(temp);
	}
}

int COMPARE(int a, int b) {
	if (a > b) {
		return 1;
	}
	else if (a == b) {
		return 0;
	}
	else {
		return -1;
	}
}

void attach(int coefficient, int exponent, node **ptr) {
	node* temp;
	temp = (node*)malloc(sizeof(*temp));
	temp->coef = coefficient;
	temp->exp = exponent;
	temp->next = NULL;
	(*ptr)->next = temp;
	(*ptr) = temp;
}

 node* polyPointer_padd(node *a, node*b, int* count) {
	 node* c, * rear, * temp;
	 int sum;
	 rear = (node*)malloc(sizeof(node));
	 rear->next = NULL;
	 c = rear;
	 while ((a) && (b)) {
		 switch (COMPARE((a)->exp, (b)->exp)) {
			 case(1):
				 (*count)++;
				 attach((a)->coef, (a)->exp, &rear);
				 (a) = (a)->next;
				 break;
			 case(0):
				 sum = (a)->coef + (b)->coef;
				 if (sum) {
					 (*count)++;
					 attach(sum, (a)->exp, &rear);
				 }
				 (a) = (a)->next; (b) = (b)->next;
				 break;
			 case(-1):
				 (*count)++;
				 attach((b)->coef, (b)->exp, &rear);
				 (b) = (b)->next;
				 break;
		 }
	 }

	 for (;a; a = (a)->next) {
		 attach((a)->coef, (a)->exp, &rear);
	 }
	 for (;b; b = (b)->next) {
		 attach((b)->coef, (b)->exp, &rear);
	 }
	 temp = c; c = c->next; free(temp);
	 return c;
}


int main() {
	FILE* af ,*bf;
	fopen_s(&af, "a.txt", "r");
	fopen_s(&bf, "b.txt", "r");
	if (!af && !bf) {
		fprintf(stderr, "file open err");
		exit(1);
	}
	node* c = (node*)malloc(sizeof(node));
	
	int temp_coef; int temp_exp;


	node* a_first = NULL, *a_end = NULL;
	int alen;
	fscanf_s(af, "%d",&alen );
	while (fscanf_s(af, "%d %d", &temp_coef, &temp_exp) != EOF) {
		node* a = (node*)malloc(sizeof(node));
		a->coef = temp_coef;
		a->exp = temp_exp;
		a->next = NULL;
		if (a_first == NULL) {
			a_first = a;
			a_end = a;
		}
		else {
			a_end->next = a;
			a_end = a;
		}
	}
	
	node* b_first = NULL, * b_end = NULL;
	int blen;
	fscanf_s(bf, "%d", &blen);
	while (fscanf_s(bf, "%d %d", &temp_coef, &temp_exp) != EOF) {
		node* b = (node*)malloc(sizeof(node));
		b->coef = temp_coef;
		b->exp = temp_exp;
		b->next = NULL;
		if (b_first == NULL) {
			b_first = b;
			b_end = b;
		}
		else {
			b_end->next = b;
			b_end = b;
		}
	}
	node* c_first;
	int c_len = 0;
	c_first = polyPointer_padd(a_first, b_first, &c_len);

	printf("컴퓨터학부 2025003170 김동후\n");
	printf("%d ", c_len);
	node* cur = c_first;
	while (cur != NULL) {
		printf("%d %d ", cur->coef, cur->exp);
		cur = cur->next;
	}
	erase(&a_first); 
	erase(&b_first);
	erase(&c_first);
	fclose(af);
	fclose(bf);

}