#include <stdio.h>
#include <stdlib.h>

typedef struct tree {
	struct tree* lnext, * rnext;
	int key;
	int level;
}tree;

typedef struct node {
	struct node* next;
	tree* data;
}node;

node* front, * rear;

void addq(tree* ptr) {
	node* newnode = (node*)malloc(sizeof(node));
	newnode->data = ptr;
	newnode->next = NULL;

	if (!front)
		front = newnode;
	else
		rear->next = newnode;

	rear = newnode;
}

tree* deleteq() {
	if (!front) {
		return NULL;
	}
	tree* tmp;
	tmp = front->data;
	front = front->next;
	return tmp;
}


tree* mSearch(tree* root, int k) {
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


void makebinary(tree** root, int k) {
	tree* parent = mSearch(*root, k);
	
	if (parent || !*root) {
		tree* newnode = (tree*)malloc(sizeof(tree));
		newnode->key = k; newnode->lnext = newnode->rnext = NULL;
		if (!*root) {
			newnode->level = 1;
			*root = newnode;
		}
		else {
			if (parent->key > k) {
				parent ->lnext = newnode;
				newnode->level = parent->level +1 ;
			}
			else {
				parent->rnext = newnode;
				newnode->level = parent->level +1;
			}
		}
	}
}

void levelorder(tree* root) {
	rear = front = NULL;
	addq(root);
	tree* tmp;
	while (front) {
		tmp = deleteq();
		printf("%d(%d) ", tmp->key, tmp->level);
		if (tmp->lnext) {
			addq(tmp->lnext);
		}
		if (tmp->rnext) {
			addq(tmp->rnext);
		}
	}
}

void P1() {
	FILE* in;
	fopen_s(&in, "in.txt", "r");
	if (!in) return;
	int tmp;
	tree* root = NULL;
	while (fscanf_s(in, "%d", &tmp) > 0) {
		makebinary(&root, tmp);
	}
	levelorder(root);
}






int main() {
	P1();
}