/******************************************************
*	Lab	07.	함수
*	- File:	lab07_02.c
*	- ID:	2025003170	
*	- Name:	김  동후
******************************************************/
#include<stdio.h>

int main(){ 
    
    int value = 0x41424344;	//	ABCD의	ASCII	코드	hexa	값	
    char *ch = &value;
    printf("value: %#x\n", value);
    for(int i = 0 ; i < 4; i++){
        printf("ch+%d: %p, %c\n",i, (ch+i), *(ch+i));
    }
}

// *ptrint
//   ptrint의 주소에 저장된 값을 불러옴
// ptrint
//   ptrint의 주소