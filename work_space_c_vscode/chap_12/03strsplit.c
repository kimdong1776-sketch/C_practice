#include <stdio.h>

int main(){
    char c[] = "C C++ JAVA";
    printf("%s\n", c);
    c[5] = 0;
    printf("%s\n",c);
    printf("%s\n",c+6);

    c[5] = ' ';
    char *p =c;

    while(*p != 0){
        printf("%c", *p++);
    }
    printf("\n");

    return 0;

}