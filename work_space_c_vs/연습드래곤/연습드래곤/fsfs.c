#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int key;
	struct node* left;
	struct node* right;
}node;


node* rsearch(node* root,int k) {
	if (!root) return NULL;
	if (root) {
		if (root->key == k) {
			return root;
		}
		else if (root->key > k) {
			return rsearch(root->left, k);
		}
		else {
			return rsearch(root->right, k);
		}
	}
}

node* lsearch(node* root, int k) {
	for (;root;) {
		if (root->key == k) {
			return root;
		}
		else if (root->key > k) {
			root = root->left;
		}
		else {
			root = root->right;
		}
	}
	return NULL;
}

node* modifidedSearch(node* tree, int k) {
	node* par = NULL;
	while (tree) {
		if (tree->key == k) {
			return NULL;
		}
		par = tree;
		if (tree->key > k) {
			tree = tree->left;
		}
		else {
			tree = tree->right;
		}
	}
	return par;
}

void insert(node**root, int data) {
	node* tmp = modifidedSearch(root, data);
	node* ptr;
	if (tmp || !(*root)) {
		ptr = (node*)malloc(sizeof(node));
		ptr->key = data;
		ptr->left = ptr->right = NULL;
		if (!(*root)) {
			*root = ptr;
		}
		else {
			if (tmp->key > data) {
				(tmp)->left = ptr;
			}
			else {
				(tmp)->right = ptr;
			}
		}
	}
}
short visted[61] = {0};
void dfs(int v) {
	node* w = NULL;
	printf("%d", v);
	visted[v] = 1;
	for (w->key = v; w;w= w->left) {
		if (!visted[w->key]) {
			dfs(w->key);
		}
	}
}

void bfs(int v) {
	node* w;
	printf("%d", v);
	visted[v] = 1;
	front = rear = NULL;
	addq(v);
	while (front) {
		v = deleteq();
		for (w = graph[v]; w; w = w->next) {
			if (!visted[w->key]) {
				printf("%d", w->key);
				addq(w->key);
				visted[w->key] = 1;
			}
		}
	}
}

void dfs(int v) {
	node* w;
	printf("%d", v);
	visted[v] = 1;
	for (w = graph[v];w;w = w->next) {
		if (!visted[w->key]) {
			dfs(w->key);
		}
	}
}

node* insucc(node* tree) {
	node* tmp = tree->rnext;
	if (!tree->rtread) {
		while (!tmp->ltread) {
			tmp = tmp->lnext;
		}
	}
	return tmp;
}

void tinorder(node* tree) {
	node* cur = tree;
	while (1) {
		cur = insuuc(cur);
		if (cur == tree) break;
		printf("%d", cur->data);

	}

}

void pushHeap(int item, int *n) {
	int i = ++(*n);

	while (i != 1 && item > heap[i/2]) {
		heap[i] = heap[i/2];
		i /= 2;
	}
	heap[i] = ptr;
}

void pushHeap(int item, int *n) {
	int i = ++(*n);
	while (i != 1 && item > heap[i/2]) {
		heap[i] = heap[i / 2];
		i /= 2;
	}
	heap[i] = item;
}

int delete(int *n) {
	int item = heap[1];
	int temp = heap[(*n)--];
	int parent = 1; int child = 2;
	while (child <= (*n)) {
		if (child < *n && heap[child] < heap[child + 1]) {
			child++;
		}
		if (temp > heap[child]) {
			break;
		}
		heap[parent] = haep[child];
		parent = child;
		child = 2 * child;
	}

	heap[parent] = temp;
	return item;
}

int main() {
	
}