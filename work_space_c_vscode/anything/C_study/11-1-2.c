#include<stdio.h>

int main(){
    char str[] = "Good time";
    for(int i = 0; i < sizeof(str) / sizeof(char); i++){
        printf("%c", str[i]);
    }
}