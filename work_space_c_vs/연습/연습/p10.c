#include <stdio.h>
#include <stdlib.h>
typedef struct node {
	int coe;
	int exp;
	struct node* next;
}node;

int COMPARE(int a, int b) {
	if (a>b) {
		return 1;
	}
	else if (a < b) {
		return - 1;
	}
	return 0;
}


void attach(int coe, int exp, node** rear) {
	node* newnode = (node*)malloc(sizeof(node));
	newnode->next = NULL; newnode->coe = coe; newnode->exp = exp;
	(*rear)->next = newnode;
	(*rear) = newnode;
}

node* lpadd(node* afirst, node* bfirst) {
	node* cfirst = (node*)malloc(sizeof(node));
	node* cend;
	cend = cfirst;
	cend->next = NULL;
	while (afirst && bfirst) {
		switch (COMPARE(afirst->exp, bfirst->exp)) {
		case 1:
			attach(afirst->coe, afirst->exp, &cend);
			afirst = afirst->next;
			break;
		case 0:
			if (afirst->coe + bfirst->coe) {
				attach(afirst->coe+ bfirst->coe, afirst->exp, &cend);
			}
			afirst = afirst->next; bfirst = bfirst->next;
			break;
		case -1:
			attach(bfirst->coe, bfirst->exp, &cend);
			bfirst = bfirst->next;
			break;

		}
	}
	for (; afirst; afirst = afirst->next) {
		attach(afirst->coe, afirst->exp, &cend);
	}
	for (; bfirst; bfirst = bfirst->next) {
		attach(bfirst->coe, bfirst->exp, &cend);
	}
	node* temp = cfirst;
	cfirst = cfirst->next;
	free(temp);
	return cfirst;

}

int main() {
	node* afirst = NULL;
	node* bfirst = NULL;
	node* cfirst = NULL;
	node* aend = NULL;
	node* bend = NULL;
	FILE* af, * bf;
	fopen_s(&af, "a.txt", "r");
	fopen_s(&bf, "b.txt", "r");
	int exp, coe;
	fscanf_s(af, "%d", &exp);
	while (fscanf_s(af, "%d %d", &coe, &exp)>0) {
		node* newnode = (node*)malloc(sizeof(node));
		newnode->coe = coe; newnode->exp = exp; newnode->next = NULL;
		if (afirst) {
			aend->next = newnode;
			aend = newnode;
		}
		else {
			afirst = newnode;
			aend = newnode;
		}
	}
	fscanf_s(bf, "%d", &exp);
	while (fscanf_s(bf, "%d %d", &coe, &exp) > 0) {
		node* newnode = (node*)malloc(sizeof(node));
		newnode->coe = coe; newnode->exp = exp; newnode->next = NULL;
		if (bfirst) {
			bend->next = newnode;
			bend = newnode;
		}
		else {
			bfirst = newnode;
			bend = newnode;
		}
	}
	cfirst = lpadd(afirst, bfirst);
	int count = 0;
	for (node* cur = cfirst; cur; cur = cur->next) {
		count++;
	}
	printf("%d ", count);
	for (node* cur = cfirst; cur; cur = cur->next) {
		printf("%d %d ", cur->coe, cur->exp);
	}
	
}