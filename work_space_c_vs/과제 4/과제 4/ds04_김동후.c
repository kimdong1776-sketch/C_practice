#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int isPalindrome(char *arr, int left, int right) {
	if (left <= right) {
		if (arr[left] == arr[right]) {
			return(isPalindrome(arr, left + 1, right - 1));
		}
		else {
			return 0;
		}
	}
	else {
		return 1;
	}
}

int iscount(char* arr, int left, int len, int count) {

	if (left <= len) {
		if (arr[left] == 'a') {
			return iscount(arr, left + 1, len, count +1);
		}
		return iscount(arr, left + 1, len, count);
		
	}
	else {
		return count;
	}
	
}

int main() {
	printf("컴퓨터학부 2025003170 김동후\n");
	FILE* f = NULL;
	char arr[22] = { 0 };
	int count;
	fopen_s(&f, "in.txt", "r");
	if (f == NULL) {
		fprintf(stderr, "file open err");
		exit(1);
	}
	int len = 0;
	while (fgets(arr, sizeof(arr), f) != NULL) {
		count = 0;
		//fscanf_s(f, "%s", arr);
		if (arr[strlen(arr) - 1] == '\n') {
			arr[strlen(arr) - 1] = 0;
		}
		
		len = strlen(arr);
		printf("%s ", arr);
		printf("%d ", iscount(arr, 0, len, count));

		if (isPalindrome(arr, 0, strlen(arr) - 1)) {
			printf("Yes\n");
		}
		else {
			printf("NO\n");
		}
		if (feof(f)) {
			break;
		}
		
	}
	fclose(f);	
}