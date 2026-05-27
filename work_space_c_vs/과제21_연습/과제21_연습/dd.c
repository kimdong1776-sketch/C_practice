#include <stdio.h>
#include <stdlib.h>

typedef struct element {
	char data[10];
} element;

void myprint(element a[], int p) {
	char tmp;
	for (int i = 0; i < 10; i++) {
		tmp = a[p].data[i];
		if (90 < tmp) {
			printf("%c", tmp);
		}
		
	}
	printf("\n");
}

int digit(element a, int i, int d) {
	char ch = a.data[i];
	if (ch >= 'a' && ch <= 'z') return ch - 'a';
	return 0;
}

int radixsort(element a[], int link[], int d, int r, int n) {
	int* front, * rear;
	front = (int*)calloc(r, sizeof(int));
	rear = (int*)calloc(r, sizeof(int));
	int i, bin, current, first, last;
	first = 1;

	for (i = 1; i < n; i++) link[i] = i + 1;
	link[n] = 0;
	for (i = d - 1; i >= 0; i--) {
		for (bin = 0; bin < r; bin++) front[bin] = 0;
		for (current = first; current; current = link[current]) {
			bin = digit(a[current], i, r);
			if (front[bin] == 0) front[bin] = current;
			else link[rear[bin]] = current;
			rear[bin] = current;
		}

		for (bin = 0; bin < r && !front[bin]; bin++);
		if (bin < r) {
			first = front[bin];
			last = rear[bin];
			for (bin++; bin < r; bin++) {
				if (front[bin]) {
					link[last] = front[bin];
					last = rear[bin];
				}
			}
			link[last] = 0;
		}
	}
	free(front);
	free(rear);
	return first;
}

void P1() {
	printf("문제 1:\n");
	FILE* in;
	fopen_s(&in, "in.txt", "r");
	if (!in) {
		fprintf(stderr, "file open err\n");
		return;
	}

	char carr[20];
	int Lsize = 0;
	while (fgets(carr, sizeof(carr), in)) {
		Lsize++;
	}

	if (Lsize == 0) {
		fclose(in);
		return;
	}

	fseek(in, 0, SEEK_SET);
	element* a = (element*)malloc(sizeof(element) * (Lsize + 1));

	for (int i = 1; i <= Lsize; i++) {
		fgets(carr, sizeof(carr), in);
		for (int j = 0; j < 10; j++) {
			char ch = carr[j];
			if (ch == '\n' || ch == '\r' || ch == '\0') {
				for (int k = j; k < 10; k++) {
					a[i].data[k] = 'A';
				}
				break;
			}
			a[i].data[j] = ch;
		}
	}
	fclose(in);

	int* link = (int*)calloc(Lsize + 1, sizeof(int));
	int head = radixsort(a, link, 10, 26, Lsize);

	for (int p = head; p != 0; p = link[p]) {
		myprint(a, p);
	}

	free(a);
	free(link);
}

int main() {
	printf("학부:컴퓨터학부 학번:2025003170 이름:김동후\n");
	P1();
	return 0;
}