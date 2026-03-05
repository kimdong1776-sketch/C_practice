#include <stdio.h>
#include <string.h>
union udata{
    int i;
    float f;
    char str[20];
};

int main(){
    union udata data1 = {10};

    data1.i = 20;  
    printf("data1.i = %d\n", data1.i);

    printf("sizeof(udata): %zd, sizeof(data1): %zd\n", sizeof(union udata), sizeof(data1));

    union udata data2= {.f = 3.14f};
    printf("data2.f = %f\n", data2.f);

    union udata data3;
    strcpy(data3.str, "hello Union");
    printf("data3.str = %s\n", data3.str);

    return 0;
}