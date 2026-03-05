/******************************************************
 *	- File:	hw05_01.c
 *	- ID:	2025003170
 *	- Name:	김  동후
 ******************************************************/

#include <stdio.h>

int main(){
    int array[] = {2, 4, 7, 8, 7, 3, 7, 9, 2, 1};
    int num, len_array, count = 0;
    len_array = (int) (sizeof(array) / sizeof(array[0]));
    do{
        printf("검색할 값을 입력하세요 (-1: 종료): ");
        scanf("%d", &num);
        if(num == -1){
            break;
        }

        for(int i = 0; i < len_array; i++){
            if(array[i] == num){
                printf("검색 인덱스: %d\n", i);
                count ++;
            }
        }
        if(count == 0){
            printf("배열에 존재하지 않습니다.\n");
        }
        else{
            printf("숫자 %d -> 총 검색 개수: %d\n",num, count);
            count = 0;
        }
    }while(1);
    printf("프로그램 종료");
    return 0; 
}