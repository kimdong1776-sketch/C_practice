#include<stdio.h>
#include<string.h>

void reverse(char *str){
    int j = strlen(str) - 1;
    for(int i = 0; i < j; i++, j--){
        char c = str[i];
        str[i] = str[j];
        str[j] = c;
    }

}
int main(){
    char s[50];
    char * str = "Hello World";
    memcpy(s, str, strlen(str)+1);
    printf("%s\n", s);

    reverse(s);
    printf("%s", s);

    return 0;
}