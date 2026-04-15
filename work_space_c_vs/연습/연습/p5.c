#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int exp;
	int coef;
}element;

int COMPARE(int a, int b) {
	if (a > b) {
		return 1;
	}
	else if (a < b) {
		return -1;
	}
	return 0;
}

element padd(element *a,int faidx, element *b, int fbidx) {
	FILE* out;
	fopen_s(&out, "c.txt", "w");
	int saidx = 0, sbidx = 0;

	while (saidx <= faidx && sbidx <= fbidx) {
		switch (COMPARE(a[saidx].exp, b[sbidx].exp)) {
			case 1: // a°¡ Å­
				attch(a[saidx].coef, a[saidx].exp)
				break;
			case 0:
				break;
			case -1:
				break;
		}
	}
}

int main() {
	FILE* in ,* in2;
	fopen_s(&in, "b.txt", "r");
	fopen_s(&in2, "a.txt", "r");
	
	int Alen, Blen;
	
	element a[100] = { 0 };
	element b[100] = { 0 };
	int i = 0;
	fscanf_s(in, "%d", &Alen);
	while (fscanf_s(in, "%d %d", &a[i].coef, &a[i++].exp) > 0);
	i = 0;
	fscanf_s(in2, "%d", &Blen);
	while (fscanf_s(in2, "%d %d", &b[i].coef, &b[i++].exp) > 0);

	padd(a,Alen, b,Blen);
}