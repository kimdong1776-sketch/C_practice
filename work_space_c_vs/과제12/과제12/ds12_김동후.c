#include <stdio.h>
#include<stdlib.h>

typedef struct node {
	int data;
	struct node* lnext, * rnext;
}node;

void madeBinaryTree(int n, node *ptr) {
	if (n > 5) {
		ptr->lnext = NULL;
		ptr->rnext = NULL;
		return;
	}

	node* lnode = (node*)malloc(sizeof(node));
	node* rnode = (node*)malloc(sizeof(node));

	lnode->data = n * 2;
	rnode->data = n + 2;

	ptr->lnext = lnode;
	ptr->rnext = rnode;
	
	madeBinaryTree(lnode->data, lnode);

	madeBinaryTree(rnode->data, rnode);

}

void inorder(node* ptr) {
	if (!ptr) return;
	inorder(ptr->lnext);
	printf("%d ", ptr->data);
	inorder(ptr->rnext);

}

void P1() {
	int n;
	printf("문제 1:\n");
	printf("scanf_s 입력: ");
	scanf_s("%d", &n);
	node* root = (node*)malloc(sizeof(node));
	root->data = n;
	madeBinaryTree(n, root);

	inorder(root);
}

void inorder_leaf(node* ptr) {
	if (!ptr) return;
	inorder_leaf(ptr->lnext);
	if (ptr->lnext == NULL && ptr->rnext == NULL) {
		printf("%d ", ptr->data);
	}
	inorder_leaf(ptr->rnext);
	
}

void P2() {
	int n;
	printf("문제 2:\n");
	printf("scanf_s 입력: ");
	scanf_s("%d", &n);
	node* root = (node*)malloc(sizeof(node));
	root->data = n;
	madeBinaryTree(n, root);
	inorder_leaf(root);
}

int main() {
	printf("컴퓨터학부 2025003170 김동후\n");
	P1();
	printf("\n");
	P2();
}