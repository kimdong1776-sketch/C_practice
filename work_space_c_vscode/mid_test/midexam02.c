/******************************************************
*	- File:	midexam02.c
*	- ID:	2025003170	
*	- Name:	김  동후
******************************************************/

#include <stdio.h>
#include <ctype.h>

int check_password(char array[], int);

int main(){ //패스워드 규칙 총10글자 (10글자 미만도 정상) 알파벳 대문자 1개 소문자 6개, 숫자 2개
    char char_array[10] = {0};
    int running = 1;
    do{
    printf("Please type password: ");
    scanf("%s", char_array);
    if(check_password(char_array, 10)){
        running = 0;
    }
    
    }while(running);
    return 0;
}

int check_password(char array[], int n){
    int capital = 0, lower = 0, digit_count = 0, special_char = 0, other_char = 10;
    int right = 0;
    char ch;
    char special[7] = {'!', '@', '#', '$', '%', '&', '*'};
    for(int i = 0 ; i < n ; i++){
        ch = array[i];
        if(isalnum(ch)){
            if(isalpha(ch)){
                if(isupper(ch)){
                    capital++;
                }
                else{
                    lower++;
                }
            }
            else if(isdigit(ch)){
                digit_count++;
            }
        }
        else{
            for(int c=0 ; c < 7; c++){
                if(ch == special[c]){
                    special_char++;
                    continue;
                }                    
            }
        }
    }



    other_char -= (capital+ lower + digit_count + special_char);
    printf("--------------------------------\n");
    printf("Password Characters\n");
    printf("Alphabet(capital: %d, lower: %d)\n", capital, lower);
    printf("Digit count: %d\n", digit_count);
    printf("Specified special char: %d\n", special_char);
    printf("Other special char : %d\n", other_char);
    printf("--------------------------------\n");

    if(other_char){
        right = 0;
    }
    else if((capital == 1) && (lower == 6) && (digit_count == 2) && (special_char==1)){
        right = 1;
    }

    if(right == 1){
        printf("You can use the password: ");
        for(int i = 0 ; i < n; i++){
            printf("%c", array[i]);
        }
        return 1;
    }
    else{
        printf("Wrong password. Please Type password again!\n");
        return 0;
    }
   
}