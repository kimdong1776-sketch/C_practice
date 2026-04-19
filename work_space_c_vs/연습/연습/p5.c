#include <stdio.h>
#include <stdlib.h>
typedef struct {
	int exp;
	int coe;
}polynomial;

int COMPARE(int a, int b) {
	if (a > b) {
		return 1;
	}
	else if (a == b) {
		return 0;
	}
	return -1;
}

void attach(int coe, int exp, polynomial *c, int* idx) {
	c[(*idx)].coe = coe;
	c[(*idx)].exp = exp;
	*idx += 1;
}

int padd(polynomial *a, polynomial *b, polynomial* c, FILE* cf, int alen, int blen) {
	
	int sum = 0;
	int aP= 0, bP = 0;
	int idx = 0;
	int count = 0;
	while (aP < alen && bP < blen) {
		switch (COMPARE(a[aP].exp, b[bP].exp)) {
		case 1:
			attach(a[aP].coe, a[aP].exp, c, &idx);
			aP++;
			count++;
			break;
		case -1:
			attach(b[bP].coe, b[bP].exp, c, &idx);
			bP++;
			count++;
			break;
		case 0:
			sum = a[aP].coe + b[bP].coe;
			if (sum) {
				attach(sum, a[aP].exp, c, &idx);
				count++;
			}
			aP++; bP++;
			break;
		}
	}
	for (;aP < alen ;aP++) {
		attach(a[aP].coe, a[aP].exp, c, &idx);
		count++;
	}
	for (;bP < blen ;bP++) {
		attach(b[bP].coe, b[bP].exp, c, &idx);
		count++;
	}
	return count;
}


int main() {
	polynomial *a;
	polynomial *b;
	polynomial *c;
	FILE* af;
	FILE* bf;
	FILE* cf;
	fopen_s(&af, "a.txt", "r");
	fopen_s(&bf, "b.txt", "r");
	fopen_s(&cf, "c.txt", "w");
	int alen = 0;
	int blen = 0;
	int clen = 0;
	if (!af || !bf || !cf) {
		exit(1);
	}
	fscanf_s(af, "%d", &alen);
	fscanf_s(bf, "%d", &blen);
	c = (polynomial*)malloc(sizeof(polynomial) * (alen + blen));
	a = (polynomial *)malloc(sizeof(polynomial) * alen);
	b = (polynomial *)malloc(sizeof(polynomial) * blen);
	
	for (int i = 0; i < alen; i++) {
		fscanf_s(af, "%d %d", &a[i].coe, &a[i].exp);
	}
	for (int i = 0; i < blen; i++) {
		fscanf_s(bf, "%d %d", &b[i].coe, &b[i].exp);
	}
	
	clen = padd(a, b, c, cf, alen, blen);

	fprintf(cf,"%d\n", clen);
	
	for (int i = 0; i < clen; i++) {

		fprintf(cf,"%d %d ", c[i].coe, c[i].exp);

	}
	free(a);
	fclose(af);
	free(b);
	fclose(bf);
	free(c);
	fclose(cf);
}