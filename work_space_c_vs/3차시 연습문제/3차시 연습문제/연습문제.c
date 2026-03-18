#include <stdio.h>

int main() {
    int N;
    int result;

    while (1) {
        result = 0;
        printf("(scanf) ");

        
        if (scanf_s("%d", &N) != 1) break;

        
        while (N > 0) {
            if (N % 2 == 1) { 
                result++;
            }
            N /= 2;
        }

        printf("%d\n", result);
    }

    return 0;
}