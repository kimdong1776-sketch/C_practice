#include<stdio.h>

int main(){
    char s[100];
    printf("Input a setntecn: ");
    fgets(s, 100, stdin);

    char *p = s;
    while(*p != 0){
        printf("%c", *p);
        p++;
        
    }
    printf("\n");
    return 0;
}