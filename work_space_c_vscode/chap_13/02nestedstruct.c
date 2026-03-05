#include <stdio.h>
#include <string.h>

struct date{
    int year;
    int month;
    int day;
};

struct account{
    struct date open;
    char name[12];
    int actnum;
    double balance;
};

int main(){
    struct account me = {
        {2022,3,9},
        "hong",
        1001,
        2000
    };
    printf("구조체 크기: %zu\n", sizeof(me));
    printf("[%d. %d. %d]\n", me.open.year, me.open.month, me.open.day);
    printf("%s %d %.2f\n", me.name, me.actnum, me.balance);

    return 0;
}