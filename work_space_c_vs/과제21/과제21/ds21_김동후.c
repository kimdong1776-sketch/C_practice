#include <stdio.h>
#include <stdlib.h>

typedef struct element {
	int data[4];
} element;

void myprint(element a[], int p) {
	int tmp;
	for (int i = 0; i < 4; i++) {
		tmp = a[p].data[i];
		if (tmp > 9) {
			printf("%c", tmp + 55);
		}
		else {
			printf("%d", tmp);
		}
	}
	printf("\n");
}

int digit(element a, int i, int d) {
	return a.data[i];
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

	char ch;
	int count = 0;
	while (fscanf_s(in, " %c", &ch, 1) > 0) {
		count++;
	}

	int Lsize = count / 4;
	if (Lsize == 0) {
		fclose(in);
		return;
	}

	fseek(in, 0, SEEK_SET);
	element* a = (element*)malloc(sizeof(element) * (Lsize + 1));

	for (int i = 1; i <= Lsize; i++) {
		for (int j = 0; j < 4; j++) {
			fscanf_s(in, " %c", &ch, 1);
			if (ch > 64) {
				a[i].data[j] = ch - 55;
			}
			else  {
				a[i].data[j] = ch - '0';
			}
		}
	}
	fclose(in);

	int* link = (int*)calloc(Lsize + 1, sizeof(int));
	int head = radixsort(a, link, 4, 16, Lsize);

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