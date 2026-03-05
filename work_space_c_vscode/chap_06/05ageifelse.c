#include<stdio.h>

int main(){

    int age = 0;

    printf("당신의 나이는? ");
    scanf("%d, &age");

    if(age > 65){
        printf("age >= 65\n");
    }
    else if(age>=20){
        printf("20<=age < 65\n");
    }
    else{
        printf("age < 20\n");
    }

    return 0;
}