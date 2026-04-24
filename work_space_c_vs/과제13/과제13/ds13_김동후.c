#include <stdio.h>
#include <stdlib.h>


typedef struct node {
	int data;
	struct node* lnext, * rnext;
}node;

node* modifiedSearch(node* root, int k) {
	node* temp = root;
	node* parent = NULL;

	//  트리가 비어있으면 NULL 반환 (조건 1)
	if (!root) return NULL;

	// . 트리를 내려가며 탐색
	while (temp) {
		//  k를 찾았다면? 중복이라서 넣으면 안 되니까 NULL 반환
		if (k == temp->data) return NULL;

		// 부모가 될 수도 있는 현재 노드를 기억해둠
		parent = temp;

		// k 값에 따라 왼쪽 또는 오른쪽으로 이동
		if (k < temp->data)
			temp = temp->lnext;
		else
			temp = temp->rnext;
	}

	//  탐색에 실패했다면(temp가 NULL이 됨), 마지막으로 머물렀던 노드가 부모!
	return parent;
}


void madeBinaryTree(node* root, int k) {

	node* ptr, * temp = modifiedSearch(root, k);

	if (temp || !(root)) {
		ptr = (node*)malloc(sizeof(node));
		ptr->data = k;
		ptr->lnext = ptr->rnext = NULL;
		if (root) {
			if (k < temp->data) temp->lnext = ptr;
			else temp->rnext = ptr;
		}
		else root = ptr;
	}

}
void inorder(node* ptr) {
	if (!ptr) return;
	inorder(ptr->lnext);
	printf("%d ", ptr->data);
	inorder(ptr->rnext);

}

int iterSearch(node* root, int k) {
	int level = 1;
	while (root) {
		if (k == root->data) {
			return level;
		}
		if (k < root->data) {
			level++;
			root = root->lnext;
		}
		else {
			level++;
			root = root->rnext;
		}
		
	}
	return 0;
}

int main() {
	printf("학부:컴퓨터학부 학번:2025003170 이름:김동후\n");
	FILE* in = NULL;
	FILE* search = NULL;
	fopen_s(&in, "in.txt", "r");
	fopen_s(&search, "search.txt", "r");

	if (!in || !search) {
		fprintf(stderr, "file open err\n");
		exit(1);
	}

	node* root = NULL;
	int temp;
	root = (node*)malloc(sizeof(node));
	fscanf_s(in, "%d", &(root->data));
	root->lnext = root->rnext = NULL;
	while (fscanf_s(in, "%d", &(temp)) > 0) {
		madeBinaryTree(root, temp);
	}

	//inorder(root);
	fclose(in);
	
	while (fscanf_s(search, "%d", &temp) > 0) {
		if ((temp = iterSearch(root, temp))) {
			printf("%d ", temp);
		}
		else {
			printf("F ");
		}
	}
	
	fclose(search);
}