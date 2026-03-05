#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(){
    char message[] = "123456789";
    int len = strlen(message);
    for(int i = 0 ; i< len ; i++){
        system("cls");
        printf("%c\n", message[i]);
        usleep(1000*1000);
    }
    return 0;
}