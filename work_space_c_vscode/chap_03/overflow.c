#include <stdio.h>

int main(){

    char c1 = 127;
    printf("127: 0x%x, %d\n",c1, c1);
    c1= c1 +1;
    printf("127+1: 0x%x, %d\n", c1, c1);


    unsigned char c2 = 255;
    printf("255: 0x%x, %d\n", c2,c2);

    c2 += 1;
    printf("255+1: 0x%x, %d\n",c2,c2);

    char c3 = -1;
    printf("-1: ox%x, %d\n", c3,c3);

    return 0;
}