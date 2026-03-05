#include<stdio.h>
#include<string.h>

struct account{
    char name[12];
    int actnumm;
    double balance;
};

int main(){
    struct account mine = {
        "홍길동",
        1001,
        100000
    };
    struct account yours;
    strcpy(yours.name, "이동원");
    yours.actnumm = 1002;
    yours.balance = 50000000;
    
    printf("구조체 크기: %zu\n", sizeof(mine));
    printf("%s %d %.2f\n", mine.name, mine.actnumm, mine.balance);
    printf("%s %d %.2f\n", yours.name, yours.actnumm, yours.balance);
    
    struct account me = {.name = "홍길동", .balance = 50000};
    printf("%s %d %.2f\n", me.name, me.actnumm, me.balance);
    
    struct account you;
    you = (struct account){.name = "김파이", .balance = 70000};
    printf("%s %d %.2f\n", you.name, you.actnumm, you.balance);
    
    return 0;
}   