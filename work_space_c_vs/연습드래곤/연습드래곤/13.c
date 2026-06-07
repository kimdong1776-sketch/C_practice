#include <stdio.h>
#include <stdlib.h>

typedef struct tree {
	struct tree* rnext, * lnext;
	int key;
}tree;

typedef struct node {
	tree* data;
	struct node* next;
}node;

node* front, * rear;

void addq(tree* ptr) {

	node* newnode = (node*)malloc(sizeof(node));
	newnode->data = ptr;
	newnode->next = NULL;
	if (!front) {
		front = newnode;
	}
	else {
		rear->next = newnode;
	}
	rear = newnode;
}

tree* deleteq() {
	if (!front) {
		return NULL;
	}
	node* tmp = front;
	tree* retur = front->data;
	front = front->next;
	free(tmp);
	return retur;
}

tree* modifiedSearch(tree* root, int k) {
	if (!root) return NULL;
	tree* parent = NULL;
	while (root) {
		if (root->key == k) return NULL;
		parent = root;
		if (root->key > k) {
			root = root->lnext;
		}
		else {
			root = root->rnext;
		}
	}
	return parent;
}

void makebinarytree(tree** root, int k) {
	tree* parent = modifiedSearch(*root, k);
	if (parent || !*root) {
		tree* newnode = (tree*)malloc(sizeof(tree));
		newnode->key = k; newnode->lnext = NULL; newnode->rnext = NULL;
		if (!*root) *root = newnode;
		else {
			if (parent->key > k) {
				parent -> lnext = newnode;
			}
			else {
				parent->rnext = newnode;
			}
		}
	}
}

short binarySearch(tree* root, int k) {
	if (!root) return 0;
	while (root) {
		if (root->key == k) {
			return 1;
		}
		else {
			if (root->key > k) {
				root = root->lnext;
			}
			else {
				root = root->rnext;
			}
		}
	}
	return 0;
}

void levelorder(tree* root) {
	rear = front = NULL;
	addq(root);
	tree* tmp;
	while (front) {
		tmp = deleteq();
		printf("%d ", tmp->key);
		if (tmp->lnext) { 
			addq(tmp->lnext);
		}
		if(tmp->rnext) {
			addq(tmp->rnext);

		}
	}
}

void P1() {
	FILE* in;
	fopen_s(&in, "in.txt", "r");
	if (!in) return;


	tree* root= NULL;
	char c; int tmp;
	while (fscanf_s(in, " %c", &c, 1)>0) {
		fscanf_s(in, "%d", &tmp);
		if (c == 'A') {//insert
			makebinarytree(&root, tmp);
			printf("A %d:",tmp);
			levelorder(root);
			printf("\n");
		}
		else {//search
			if (binarySearch(root, tmp)) {
				printf("S %d: %d is in T", tmp, tmp);
			}
			else {
				printf("S %d: %d is not in T", tmp, tmp);
			}
			printf("\n");
		}
	}
}

int main() {
	P1();

}