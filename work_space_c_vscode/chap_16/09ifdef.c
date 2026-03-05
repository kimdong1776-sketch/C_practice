#include <stdio.h>
// #define DEBUG
#define LIMIT 20

int main(){
    long long prod = 1;
    for (int i = 1; i <= LIMIT; i++){
        prod *= i;

#ifdef DEBUG
            if(i % 5 == 0){
                printf("DEBUG : 1 to %2d 의 곱은 %d입니다.\n\n\n\n\n", i, prod);
            }
#endif
    }
    printf("1부터 %d까지의 곱은 %ld 입니다.\n", LIMIT, prod);

    return 0;
}