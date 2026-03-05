#include<stdio.h>
#include<string.h>

int main(){
    char str[] = "Hello, world!";
    char *strsearch = "world";
    char ch = 'o';
    char *p1, *p2;

    p1 = strstr(str, strsearch);
    if(p1){
        printf("strstr(%s) 위치: %td \n", strsearch, (p1 - str));
    }
    else{
        printf("strstr(%s) 없음\n", strsearch);
    }

    p2 = strchr(str, ch);
    if(p2){
        printf("strchr(%c) 위치: %td \n", ch, (p2 - str));
    }
    else{
        printf("strchr(%c) 없음\n",ch);
    }

    return 0;

}