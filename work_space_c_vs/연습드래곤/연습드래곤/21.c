#include <stdio.h>
#include <stdlib.h>

typedef struct element {
	int d[4];
}element;


int radixsort(element a[], int link[], int d, int r, int n) {
	int* front = (int*)malloc(sizeof(int)*r);
	int* rear = (int*)malloc(sizeof(int)*r);
	int i, bin, current, first, last;
	first = 1;
	for (i = 1; i < n; i++)link[i] = 1 + i;
	link[n] = 0;

	for (i = d - 1; i >= 0;i--) {
		for (bin = 0; bin < r; bin++)front[bin] = 0;
		for (current = first; current; current = link[current]) {
			bin = a[current].d[i];
			if (front[bin] == 0) front[bin] = current;
			else link[rear[bin]] = current;
			rear[bin] = current;
		}

		for (bin = 0; !front[bin]; bin++);
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
	return first;
}

int myconvert(char ch) {
	if (65 <= ch) {
		return ch - 55;
	}
	else {
		return ch - 48;
	}
}
void myprintf(int d) {
	if (d > 9) {
		printf("%c", d+55);
	}
	else {
		printf("%c", d+48);

	}
}
void P1() {
	FILE* in;
	fopen_s(&in, "in.txt", "r");
	if (!in) {
		fprintf(stderr,"file open err\n");
		exit(1);
	}
	char ch;
	int count = 0;
	while (fscanf_s(in, " %c", &ch, 1) > 0) {
		count++;
	}
	fseek(in, 0, SEEK_SET);
	count /= 4;
	element* a = (element*)malloc(sizeof(element) * (count + 1));
	int* link = (int*)malloc(sizeof(int)*(count+1));
	for (int i = 1; i <= count;i++) {
		for (int j = 0; j < 4; j++) {
			fscanf_s(in, " %c", &ch,1);
			ch = myconvert(ch);
			a[i].d[j] = ch;
			
		}
	}
	
	int first = radixsort(a,link, 4,16,count);

	for (int i = first; i;i = link[i]) {
		for (int j = 0; j < 4; j++) {
			myprintf(a[i].d[j]);
		}
		printf("\n");
	}

}

int main() {
	P1();
}