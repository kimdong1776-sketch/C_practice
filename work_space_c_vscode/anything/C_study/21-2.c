#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
int main(){
    char str[21] = {0};
    int len = 0;
    fgets(str, sizeof(str), stdin);
    len = strlen(str);
    str[len-1] = '\0';
    int sum = 0;
    for(int i = 0 ; i < len ; i++){
        if (str[i] >= '0' && str[i] <= '9'){
            sum += str[i] - '0';
        }
    }
    printf("%d", sum);
}