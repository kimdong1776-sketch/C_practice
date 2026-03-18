#include <stdio.h>
#include <stdlib.h>
int isprime(int x, int y) {
	if (x == 1 || y == 1) {
		return 1;
	}
	else if (x != 1 && y != 1 && x == y) {
		return 0;
	}
	else if (x != 1 && y != 1 && x < y) {
		return(isprime(x, y - x));
	}
	else if (x != 1 && y != 1 && x > y) {
		return(isprime(x-y,y));
	}

}

int main() {
	FILE* f = NULL;
	fopen_s(&f, "in.txt", "r");
	if (f == NULL) {
		exit(1);
	}
	int x, y;
	while (fscanf_s(f, "%d %d", &x, &y) != 0) {
		//fscanf_s(f,"%d %d", &x, &y);
		if (x <= 0 || y <= 0) {
			break;
		}
		printf("%d %d ", x,y);
		
		if (isprime(x,y) == 1) {
			printf("true\n");
		}
		else {
			printf("false\n");
		}
		if(feof(f)) {
			break;
		}
	}
	fclose(f);
}