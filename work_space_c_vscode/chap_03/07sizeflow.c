#include <stdio.h>

int main(){
    printf(" 자료형: 크기(바이트)\n");
    printf("       char : %zd\n", sizeof(char));
    printf("        int : %zd %zd\n", sizeof(int), sizeof(200));
    printf("  long long : %zd %zd\n", sizeof(long long), sizeof(900LL));
    printf("      float : %zd %zd\n", sizeof(float), sizeof 3.14F);
    printf("long double : %zd %zd\n", sizeof(long double), sizeof 3.24L);
    short s = 32767;
    printf("%d\n", s); s = s + 1;
    printf("%d\n", s);
    return 0;
}