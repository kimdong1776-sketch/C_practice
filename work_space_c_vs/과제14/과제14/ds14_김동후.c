#include <stdio.h>
#include <stdlib.h>

typedef struct tree {
	int data;
	int level;
	struct tree* lnext;
	struct tree* rnext;
}tree;

typedef struct node {
	tree* element;
	struct node* next;
}node;

node* qfirst = NULL;
node* qrear = NULL;

void addq(tree* i) {
	node* temp = (node*)malloc(sizeof(node));
	temp->element = i; temp->next = NULL;
	if (qfirst) {
		qrear->next = temp;
	}
	else {
		qfirst = temp;
	}
	qrear = temp;
}

tree* deleteq() {
	if (!qfirst) {
		fprintf(stderr, "queue is empty\n");
		exit(1);
	}
	node* item = qfirst;
	qfirst = qfirst->next;
	return (item->element);
}

void levelOrder(tree* ptr) {
	ptr->level = 1;
	if (!ptr) return;

	addq(ptr);

	while (qfirst) {
		ptr = deleteq();
		printf("%d(%d) ", ptr->data,ptr->level);
		if (ptr->lnext) {
			addq(ptr->lnext);
			ptr->lnext->level = ptr->level +1;
		}
			
		if (ptr->rnext) {
			addq(ptr->rnext);
			ptr->rnext->level = ptr->level + 1;
		}		
	}
}

tree* modifiedSearch(tree* root, int k) {
	tree* temp = root;
	tree* parent = NULL;
	if (!root) return NULL;
	while (temp) {
		if (k == temp->data) return NULL;
		parent = temp;
		if (k < temp->data)
			temp = temp->lnext;
		else
			temp = temp->rnext;
	}
	return parent;
}


void madeBinaryTree(tree** root, int k) {
	tree* ptr, * temp = modifiedSearch(*root, k);

	if (temp || !(*root)) { 
		ptr = (tree*)malloc(sizeof(tree));
		ptr->data = k;
		ptr->lnext = ptr->rnext = NULL;
		if ((*root)) {
			if (k < temp->data) temp->lnext = ptr;
			else temp->rnext = ptr;
		}
		else (*root) = ptr;
	}

}

int main() {
	printf("학부:컴퓨터학부 학번:2025003170 이름:김동후\n");
	
	FILE* in;
	fopen_s(&in,"in.txt", "r");
	if (!in) {
		fprintf(stderr,"file open err\n");
		exit(1);
	}
	tree* root = NULL;
	int temp;
	
	while (fscanf_s(in, "%d", &temp)>0) {

		madeBinaryTree(&root,temp);
	}
	
	levelOrder(root);

	return 0;
}