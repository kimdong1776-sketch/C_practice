#include <stdio.h>
#include <stdlib.h>

typedef struct element {
	int num;
	char ch;
}element;

int listMerge(element a[], int link[], int start1, int start2) {
	int last1, last2, lastResult = 0;
	for (last1 = start1, last2 = start2; last1 && last2;) {
		if (a[last1].num <= a[last2].num) {
			link[lastResult] = last1;
			lastResult = last1; last1 = link[last1];
		}
		else {
			link[lastResult] = last2;
			lastResult = last2; last2 = link[last2];
		}
	}
	if (last1 == 0) link[lastResult] = last2;
	else link[lastResult] = last1;
	return link[0];
}
int rmergeSort(element a[], int link[], int left, int right) {
	if (left >= right) {
		return left;
	}
	int mid = (left + right) / 2;
	return listMerge(a, link, rmergeSort(a, link, left, mid), rmergeSort(a, link, mid + 1, right));
}


void P1() {
	FILE* in;
	fopen_s(&in, "in.txt", "r");
	if (!in) return;

	int n, tmp, len = 0;
	char c;
	while (fscanf_s(in, "%d", &n) > 0) {
		fscanf_s(in, " %c", &c,1);
		len++;
	}
	fseek(in, 0, SEEK_SET);

	element* arr = (element*)malloc(sizeof(element)*(len+1));
	int* link = (int*)calloc((len + 1),sizeof(int));

	for (int i = 1; i <= len; i++) {
		fscanf_s(in, "%d", &n);
		fscanf_s(in, " %c", &c,1);
		arr[i].num = n;
		arr[i].ch = c;
	}
	
	int head = rmergeSort(arr, link, 1, len);

	for (int i = head;i;i = link[i]) {
		printf("%d %c\n", arr[i].num, arr[i].ch);
	}
}
//========

element* heap;
void swap(element* a, element* b) {
	element tmp = *a;
	*a = *b;
	*b = tmp;
}
void adjust( int root, int n) {
	int h = heap[root].num;
	int ch = heap[root].ch;
	int child = 2*root;
	while (child <= n) {
		if (child < n && heap[child].num < heap[child + 1].num) child++;
		if (h > heap[child].num) break;
		heap[child / 2] = heap[child];
		child *= 2;
	}
	heap[child / 2].num = h;
	heap[child / 2].ch = ch;
}
void heapsort( int n) {
	for (int i = n / 2; i > 0;i--) {
		adjust( i, n);
	}
	for (int i = n; i>0;i--) {
		swap(&heap[i], &heap[1]);
		adjust( 1, i-1);
	}
}



void P2() {
	FILE* in; 
	fopen_s(&in,"in.txt", "r");

	if (!in) return;

	int n, tmp, len = 0;
	char c;
	while (fscanf_s(in, "%d", &n) > 0) {
		fscanf_s(in, " %c", &c, 1);
		len++;
	}
	fseek(in, 0, SEEK_SET);

	heap = (element*)malloc(sizeof(element) * (len + 1));

	for (int i = 1; i <= len; i++) {
		fscanf_s(in, "%d", &n);
		fscanf_s(in, " %c", &c, 1);
		heap[i].num = n;
		heap[i].ch = c;
	}
	
	heapsort(len);

	for (int i = 1; i <= len; i++) {
		printf("%d %c\n", heap[i].num, heap[i].ch);
	}
}

int main() {
	//P1();
	P2();
}