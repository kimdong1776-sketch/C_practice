#include <stdio.h>
#include <stdlib.h>

typedef struct tree {
	int data;
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
	temp->element = i;
	temp->next = NULL;
	if (qfirst) qrear->next = temp;
	else qfirst = temp;
	qrear = temp;
}

tree* deleteq() {
	if (!qfirst) return NULL;
	node* temp = qfirst;
	tree* element = temp->element;
	qfirst = qfirst->next;
	if (qfirst == NULL) qrear = NULL;
	free(temp); 
	return element;
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

void inserttree(tree** root, int k) {

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

short Binary_search(tree* root, int key) {
	while (root) {
		if (key == root->data) return 1;
		if (key < root->data) root = root->lnext;
		else root = root->rnext;
	}
	return 0;
}

// 오른쪽 서브트리에서 최솟값을 찾는 함수
tree* minValueNode(tree* node) {
	tree* current = node;
	while (current && current->lnext != NULL)
		current = current->lnext;
	return current;
}

tree* delettree(tree* root, int k) {
	if (root == NULL) return root;

	// 1. 일단 삭제할 노드를 찾아 내려감
	if (k < root->data)
		root->lnext = delettree(root->lnext, k);
	else if (k > root->data)
		root->rnext = delettree(root->rnext, k);

	// 2. 삭제할 노드를 찾았을 때!
	else {
		// Case 1 & 2: 자식이 없거나 하나인 경우
		if (root->lnext == NULL) {
			tree* temp = root->rnext;
			free(root);
			return temp;
		}
		else if (root->rnext == NULL) {
			tree* temp = root->lnext;
			free(root);
			return temp;
		}

		// Case 3: 자식이 두 개인 경우
		// 오른쪽 서브트리에서 가장 작은 놈(Successor)을 찾음
		tree* temp = minValueNode(root->rnext);

		// 그 값을 현재 노드에 복사
		root->data = temp->data;

		// 대타로 올라온 놈의 원래 자리를 삭제 (재귀 호출)
		root->rnext = delettree(root->rnext, temp->data);
	}
	return root;
}


void leveltraver(tree* ptr) {
	if (!ptr) return;
	addq(ptr);

	while (qfirst) {
		ptr = deleteq();
		printf("%d ", ptr->data);
		if (ptr->lnext) {
			addq(ptr->lnext);
		}

		if (ptr->rnext) {
			addq(ptr->rnext);
		}
	}
}

int main() {
	FILE* in;
	fopen_s(&in, "in.txt", "r");
	int temp;
	tree* root = NULL;
	if (!in) {
		fprintf(stderr, "fiel open errrrrrr\n");
	}

	while (fscanf_s(in, "%d", &temp) > 0) {
		inserttree(&root, temp);
	}
	int chois;
	
	while (1) {
		printf("\nScanf: ");
		scanf_s("%d", &chois);

		if (chois >= 0) {
			if (Binary_search(root, chois)) {
				root = delettree(root, chois);
			}
			else printf("not exist\n");
			leveltraver(root);
		}
		else {
			break;
		}
	}
	fclose(in);
}