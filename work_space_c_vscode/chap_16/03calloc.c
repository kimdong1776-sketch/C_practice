#include <stdio.h>
#include <stdlib.h>

void myprintf(int * ary, int n);
int main(){
    int * ary = NULL;
    ary = (int *)calloc(3, sizeof(int));
    if (ary == NULL){
        printf("메모리 애ㅑ럼ㄴ애ㅑ;ㅓㄹㅇ먀ㅐ;러");
        exit(EXIT_FAILURE);
    }
    myprintf(ary, 3);
    free(ary);
    // myprintf(ary, 3); Tmfprl rkqt 
    return 0;
}

void myprintf(int * ary, int n){
    for (int i = 0; i< n; i++){
        printf("ary[%d]= %d\n", i, *(ary + i));
    }
}