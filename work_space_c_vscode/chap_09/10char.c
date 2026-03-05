#include <stdio.h>
#include <ctype.h>

void print2char(char);

int main(){
    char ch;

    printf("알파벳(종료x) 또는 다른 문자 입력하세요. \n");
    do{
        printf("문자 입력 후 Enter: ");
        scanf("%c", &ch);
        getchar();
        if (isalpha(ch))
            print2char(ch);
        else
            printf("입력: %c\n", ch);

    }while (ch != 'x' && ch != 'x');

    return 0;

}

void print2char(char ch){
    if (isupper(ch)){
        printf("입력: %c 변환: %c", ch, tolower(ch));
    }
    else{
        
        printf("입력: %c 변환: %c", ch, toupper(ch));
    }
}