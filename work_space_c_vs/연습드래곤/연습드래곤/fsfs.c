#include <stdio.h>
#include <stdlib.h>

typedef struct tree {
	int data;
	tree* lnext, *rnext;
}tree;

typedef struct node {
	tree* data;
	node* next;
}node;

typedef struct stack {
	int data;
	stack* next;
}stack;

stack* front;

node* qfront = NULL;
node* qrear = NULL;

void addq(tree* item) {
	node* tmp = (node*)malloc(sizeof(node));
	tmp->data = item;
	tmp->next = NULL;
	if (!qfront) {
		qfront = tmp;
		qrear = tmp;
	}
	else {
		qrear->next = tmp;
		qrear = tmp;
	}

}

tree* deleteq() {
	tree* re;
	if (qfront == NULL) {
		return NULL;
	}
	else {
		re = qfront;
		qfront = qfront->next;
		return re;
	}
}


void push(int data) {
	stack* newnode = (stack*)malloc(sizeof(stack));
	newnode->data = data;
	newnode->next = NULL;
	if (front == NULL) {
		front = newnode;
	}
	else {
		newnode->next = front;
		front = newnode;
	}
}

int pop() {
	if (!front) {
		fprintf(stderr,"stack is empty\n");
		exit(1);
	}
	stack* tmp= front;
	int r = front->data;
	front = front->next;
	free(tmp);
	return r;
}

void inoder(tree * ptr) {
	if (ptr) {
		inoder(ptr->lnext);
		printf("%d", ptr->data);
		inoder(ptr->rnext);
	}
}

void preorder(tree * ptr) {
	if (ptr) {
		printf("%d", ptr->data);
		preorder(ptr->lnext);
		preorder(ptr->rnext);
	}
}

void postorder(tree * ptr) {
	if (ptr) {
		preorder(ptr->lnext);
		preorder(ptr->rnext);
		printf("%d", ptr->data);
	}
}

void iterInOder(tree* root) {

	for (;;) {
		for (;root;root = root->lnext) {
			push(root);
		}
		root = pop();
		if (!root) break;
		printf("%d", root->data);
		root = root->rnext;
	}
}

void levelorder(tree* root) {
	addq(root);
	for (;;) {
		root = deleteq();
		if (!root) {
			break;
		}
		printf("%d", root->data);
		if (root->lnext) {
			addq(root->lnext);
		}
		if (root->rnext) {
			addq(root->rnext);
		}
	}
}

tree* copy(tree* origin) {
	if (!origin) return NULL;
	tree* tmp = (tree*)malloc(sizeof(tree));
	tmp->data = origin->data;
	tmp->lnext = copy(origin->lnext);
	tmp->rnext = copy(origin->rnext);
	return tmp;
}

int equal(tree* A, tree* B) {
	return((!A && !B) || ((A&&B)&&(A->data == B->data) && equal(A->lnext, B->lnext) && equal(A->rnext, B->rnext)));
}

typedef struct Thread {
	int data;
	struct Thread* lnext, * rnext;
	short lThread, rThread;
}Thread;

Thread* insucc(Thread* root) {
	Thread* temp = root->rnext;
	if (!root->rThread) {
		while (!temp->lThread) {
			temp = root->lnext;
		}
	}
	return temp;
}

void tionorder(Thread* root) {
	Thread* cur;
	while (1) {
		cur = insucc(cur);
		if (cur == root) break;
		printf("%d", cur->data);
	}
}

//heap
int heap[20] = { 0 };

void pushH(int k, int *n) {
	if (*n == 19) {
	}
	int i = ++(*n);
	
	while (i != 1 && heap[i/2] < k) {
		heap[i] = heap[i/2];
		i /= 2;
	}
	heap[i] = k;
}

int delH(int *n) {
	if (*n == 0) {
		return 0;
	}
	int r = heap[1];
	int tmp = heap[(*n)--];
	int parent = 1, child= 2;

	while (child <= (*n)) {
		if (child < (*n)&& heap[child] < heap[child+1]) {
			child++;
		}
		if (tmp >= heap[child]) {
			break;
		}
		heap[parent] = heap[child];
		parent = child;
		child *= 2;
	}
	heap[parent] = tmp;
	return r;
}

tree* BST_rsearch(tree* root, int k) {
	if (root) {
		if (root->data == k) {
			return root;
		}
		else if (root->data > k) {
			BST_rsearch(root->lnext, k);
		}
		else {
			BST_rsearch(root->rnext, k);
		}
	}
	return NULL;
}

tree* BST_isearch(tree* root, int k) {
	while (root) {
		if (root->data == k) {
			return root;
		}
		else if(root->data > k) {
			root = root->lnext;
		}
		else {
			root = root->rnext;
		}
	}
	return NULL;
}

tree* modified_search(tree* root, int k) {
	tree* parent = NULL;
	while (root) {
		if (root->data == k) return NULL;
		parent = root;
		if (root->data > k) {
			root = root->lnext;
		}
		else {
			root = root->rnext;
		}
	}
	return parent;
}

void insert(tree**root, int k) {
	tree* parent = modified_search(*root, k);
	if (parent||!*root) {
		tree* node = (tree*)malloc(sizeof(tree));
		node->data = k;
		node->lnext = node->rnext = NULL;

		if (!*root) {
			*root = node;
		}
		else if (parent->data > k) {
			parent->lnext = node;
		}
		else {
			parent->rnext = node;
		}
	}
}

// 보조 함수 : 특정 트리에서 가장 작은 값을 가진 노드를 찾는 함수
// (주로 오른쪽 서브트리에서 최솟값을 찾을 때 사용합니다)
tree * minValueNode(tree * node) {
	tree* current = node;
	// 왼쪽 자식이 없을 때까지 계속 파고들면 그게 최솟값입니다.
	while (current && current->lnext != NULL) {
		current = current->lnext;
	}
	return current;
}

// 트리 삭제 함수 (삭제 후 갱신된 트리의 루트 포인터를 반환합니다)
tree* deleteNode(tree* root, int k) {
	// 1. Base case: 트리가 비어있거나, 지우려는 값이 없는 경우
	if (root == NULL) {
		return root;
	}

	// 2. 지우려는 값(k)을 찾아 트리 순회
	if (k < root->data) {
		root->lnext = deleteNode(root->lnext, k);
	}
	else if (k > root->data) {
		root->rnext = deleteNode(root->rnext, k);
	}
	// 3. 지우려는 값을 마침내 찾은 경우 (k == root->data)
	else {
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
		// Case 3: 자식이 2개인 경우
		tree* temp = minValueNode(root->rnext);
		root->data = temp->data;
		root->rnext = deleteNode(root->rnext, temp->data);
	}
	return root;
}


short vist[] = { 50 };
node* aList[] = { 40 };
void bfs(int v) {
	printf("%d", v);
	vist[v] = 1;
	node* tmp = NULL;
	addq(v);
	for (qfront) {
		v = deleteq();
		for (tmp = aList[v]; tmp;tmp = tmp -> next) {
			if (!vist[tmp->data]) {
				vist[tmp->data] = 1;
				printf("%d", tmp->data);
				addq(v);
			}
		}
	}

}

node* dfs(int v) {
	node* tmp;
	printf("%d", v);
	vist[v] = 1;
	for (tmp = aList[v]; tmp; tmp = tmp->next) {
		if (!vist[tmp->data]) {
			dfs(tmp->data);
		}
	}
}
//=---------
void insertA(node e, node a[], int i) {
	a[0] = e; //파수꾼의 역할;
	while (e.data < a[i].data) {
		a[i + 1] = a[i];
		i--;
	}
	a[i + 1] = e;

}

void insertionSort(node a[], int n) {
	for (int i = 2; i <= n; i++) {
		node temp = a[i];
		insertA(temp, a, i - 1);
	}
}
//---------
void swap(int* a, int *b) {
	int temp = *a;
	*a = *b;
	*b = *a;
}

void quickSort(node a[], int left, int right) {
	int pivot = a[left].data;
	
	if (left < right) {
		int i = left, j = right + 1;
		do {
			do { i++; } while (pivot < a[i].data);
			do { j--; } while (pivot > a[j].data);
			if(i < j) swap(a[i].data, a[j].data);
		} while (i < j);
		swap(&a[left], &a[j]);
		quickSort(a, left, j-1);
		quickSort(a, j +1, right );
	}
}
//---------
void merge(node initList[], node mergeLsit[], int i, int m, int n) {
	int j, k, t;
	j = m + 1;
	k = i;

	while (i <= m && j <= n) {
		if (initList[i].data <= initList[j].data) {
			mergeLsit[k++] = initList[i++];
		}
		else {
			mergeLsit[k++] = initList[j++];
		}
	}
	if (i > m) {
		for (t = j;t <= n;t++) {
			mergeLsit[k++] = initList[t];
		}
	}
	else
		for (t = i; t <= m;t++) {
			mergeLsit[k++] = initList[t];
		}
}

void mergePass(node initList[], node mergeLsit[], int n, int s) {
	int i, j;
	for (i = 1; i + 2 * s -1 <= n; i += 2*s) {
		merge(initList, mergeLsit, i,i+s-1, i+2*s-1);
	}
	if (i + s - 1 < n) {
		merge(initList, mergeLsit, i, i + s - 1, n);
	}
	else {
		for (int j = i; j <= n;i++) {
			mergeLsit[j] = initList[j];
		}
	}

}

void mergeSort(node a[], int n) {
	int s = 1;
	node extra[200];
	while (s < n) {
		mergePass(a, extra, n, s);
		s *= 2;
		mergePass(extra, a, n, s);
		s *= 2;

	}
}

//-=--- 이거좀 다시 보자
int rmergeSort(element a[], int link[], int left, int right){
	if (left >= right) return left;
	int mid = (left + right) / 2;
	return listMerge(a, link, rmergeSort(a, link, left, mid), rmergeSort(a, link, mid + 1, right));
}

//rmergeSort에서 쪼개진 두 개의 정렬된 체인(각각 start1과 start2로 시작)을 비교하여 하나의 정렬된 체인으로 병합하는 함수입니다
//link는 0으로 초기화

int listMerge(element a[], int link[], int start1, int start2){
	int last1, last2, lastResult = 0;
	for (last1 = start1, last2 = start2; last1 && last2;)
		if (a[last1] <= a[last2]) {
			link[lastResult] = last1;
			lastResult = last1; last1 = link[last1];
		}
		else {
			link[lastResult] = last2;
			lastResult = last2; last2 = link[last2];
		}
	if (last1 == 0) link[lastResult] = last2;
	else link[lastResult] = last1;
	return link[0];
}

//--- 이ㄱ좀 다시 보자

void adjsust(tree a[], int root, int n) {
	int child = 2 * root;
	int tmp = a[root];
	while (child <= n) {

		if (child < n && a[child] < a[child+1]) {
			child++;
		}

		if (a[root] > a[child]) break;
		a[child / 2] = a[child];
		child /= 2;
	}
	a[child / 2] = tmp;
}

void heapSort(node a[], int n) {
	for (int j = n / 2; j>0;j--) {
		adjsust(a, j, n);
	}
	for (int i = n - 1; i > 0;i--) {
		swap(a[i+1], a[1]);
		adjsust(a, 1, i);
	}
}

//---]

int radixsort(node a[], int link[], int d, int r, int n) {
	//몰!루
}


int main() {

}