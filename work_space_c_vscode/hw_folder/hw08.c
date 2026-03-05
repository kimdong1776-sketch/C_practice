/******************************************************
 *	- File:	hw08.c
 *	- ID:	2025003170
 *	- Name:	김  동후
 ******************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void led_display_loop(char *input_string){
    char display_string[51] = {0};
    char temp_string[51] = {0};					
    char first_char = 0;
    int len = strlen(input_string);

    strncpy(temp_string, input_string, len);
    temp_string[len] = '\0';
    strncpy(display_string, temp_string, len+1); //널문자 까지
    //마지막인덱스 널문자 처리 완료.
    for(int i = 0 ; i< 100 ; i++){
            system("cls");
            printf("%s", display_string);

            first_char = temp_string[0];
            strncpy(display_string, temp_string+1 ,len-1); //2번째 부터 마지막
            display_string[len-1] = first_char; //끝에 붙이기
                        
            strncpy(temp_string, display_string, len);
            temp_string[len] = '\0'; //혹시몰라
            usleep(1000*100);
        }
    }

int main(){
    char message[51] = {0}; //50자 이하
    int len;
    printf("Type a message(50 chars): ");
    fgets(message, sizeof(message), stdin);

    len = strlen(message);
    if (message[len - 1] == '\n'){
            message[len - 1] = '\0';
        }
    led_display_loop(message);

}