#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100
typedef struct element {
	int key;
	char data;
}element;


int rmergeSort(element a[], int link[], int left, int right, int choice) {
	if (left >= right) {
		return left;
	}
	int mid = (left + right) / 2;
	return listMerge(a, link, rmergeSort(a, link, left, mid, choice), rmergeSort(a, link, mid + 1, right, choice), choice);
	
}
int listMerge(element a[], int link[], int start1, int start2, int choice) {
	int last1, last2, lastResult = 0;
	for (last1 = start1, last2 = start2; last1 && last2;) {
		if (choice == 1) {
			if (a[last1].key <= a[last2].key) {
				link[lastResult] = last1;
				lastResult = last1; last1 = link[last1];
			}
			else {
				link[lastResult] = last2;
				lastResult = last2; last2 = link[last2];
			}
		}
		else if (choice == 2) {
			if (a[last1].data <= a[last2].data) {
				link[lastResult] = last1;
				lastResult = last1; last1 = link[last1];
			}
			else {
				link[lastResult] = last2;
				lastResult = last2; last2 = link[last2];
			}
		}
		
	}
	if (last1 == 0) link[lastResult] = last2;
	else link[lastResult] = last1;
	return link[0];
}

void P1() {
	printf("문제 1:\n");
	FILE* in;
	fopen_s(&in, "in.txt", "r");
	if (!in) {
		fprintf(stderr,"file open err\n");
	}
	int tmp;
	char c;
	int Lsize = 0;
	while (fscanf_s(in, "%d ", &tmp) > 0) {
		fscanf_s(in, "%c", &c, 1);
		Lsize++;
	}
	fseek(in, 0, SEEK_SET);
	element* a = (element*)malloc(sizeof(element) * (Lsize + 1));
	int i = 1;
	while (fscanf_s(in, "%d ", &tmp) > 0) {
		fscanf_s(in, "%c", &c, 1);
		a[i].key = tmp; a[i++].data = c;
	}
	int choice;
	fclose(in);
	printf("<scanf_s>");
	scanf_s("%d", &choice);
	int link[MAX_SIZE] = {NULL};
	
	int head = rmergeSort(a, link, 1, Lsize, choice);

	// 시작 인덱스부터 link 배열을 따라가며 체인의 순서대로 출력.
	// link[p]의 값이 0이면 더 이상 연결된 원소가 없다는 뜻. 반복 종료
	for (int p = head; p != 0; p = link[p]) {
		printf("%d %c\n", a[p].key, a[p].data);
	}
}

//p2
void SWAP(element* i, element* j) {
	element tmp = *i;
	*i = *j;
	*j = tmp;
}

void adjust(element a[], int root, int n, int choice){
	int child, rootkey;
	element temp;
	temp = a[root];
	
	if (choice == 1) {
		rootkey = a[root].key;
	}
	else if (choice == 2) {
		rootkey = a[root].data;
	}
	child = 2 * root;
	while (child <= n) {
		if ((child < n) && (a[child].key < a[child + 1].key))
			child++;
		if (choice == 1) {
			if (rootkey > a[child].key) {
				break;
			}
			else {
				a[child / 2] = a[child];
				child *= 2;
			}
		}
		else if (choice == 2) {
			if (rootkey > a[child].data) {
				break;
			}
			else {
				a[child / 2] = a[child];
				child *= 2;
			}
		}
		
	}
	a[child / 2] = temp;

}

void heapSort(element a[], int n, int choice) {
	int i, j;
	element temp;

	for (i = n / 2; i > 0; i--) {
		adjust(a, i, n, choice);
	}
	for (i = n - 1; i > 0; i--) {
		SWAP(&a[1], &a[i + 1]);
		adjust(a, 1, i, choice);
	}
}
void P2() {
	printf("문제 2:\n");
	FILE* in;
	fopen_s(&in, "in.txt", "r");
	if (!in) {
		fprintf(stderr, "file open err\n");
	}
	int tmp;
	char c;
	int Lsize = 0;
	while (fscanf_s(in, "%d ", &tmp) > 0) {
		fscanf_s(in, "%c", &c, 1);
		Lsize++;
	}
	fseek(in, 0, SEEK_SET);
	element* a = (element*)malloc(sizeof(element) * (Lsize + 1));
	int i = 1;
	while (fscanf_s(in, "%d ", &tmp) > 0) {
		fscanf_s(in, "%c", &c, 1);
		a[i].key = tmp; a[i++].data = c;
	}
	int choice;
	fclose(in);
	printf("<scanf_s>");
	scanf_s("%d", &choice);
	heapSort(a, Lsize, choice);
	for (int i = 1; i <= Lsize; i++) printf("%d %c\n", a[i].key, a[i].data);
}

int main() {
	printf("학부:컴퓨터학부 학번:2025003170 이름:김동후\n");
	P1();
	P2();
}
