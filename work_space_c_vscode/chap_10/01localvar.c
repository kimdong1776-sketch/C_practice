#include<stdio.h>>

void sub(int param);

int main(){
    int n = 10;
    printf("%d\n", n);

    for (int m = 0, sum = 0; m < 3; m++){
        sum += m;
        printf("\t%d %d\n", m, sum);
    }
    printf("%d\n", n);
    // pirntf("%d %d\n", m, sum);
    sub(20);

    return 0;
}

void sub(int param){
    int local = 100;
    pirntf("\t%d %d\n", param, local);
    // printf("%d\n", n); // error undeclear

}