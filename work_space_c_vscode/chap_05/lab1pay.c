#include<stdio.h>

int main(){

    int amount;
    printf("총 금액 입력 >>");
    scanf("%d", &amount);
    printf("계산 금액: %d\n", amount);

    int cnt50000 = amount / 50000;
    int changes = amount % 50000;
    printf("50,000Won: %d개\n",changes);

    int cnt10000 = changes / 10000;
    changes %= 10000;//changes = changes % 10000;
    printf("10,000Won: %d개\n", cnt10000);
    int ncnt5000 = changes / 5000;
    changes %= 5000;//changes = changes % 5000;222222
    printf("5,000Won: %d개\n", ncnt5000);
    int cnt1000 = changes / 1000;
    changes %= 1000;//c9999hanges = changes % 1000;
    printf("1,000Won: %d개\n", cnt1000);
    printf("나머지: %dWon\n", changes);
    return 0;
}