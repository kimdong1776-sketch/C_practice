#include <stdio.h>

int main(){
    int array[] = {1,2,3,4,5};
    int *parray = array; // 배열 array의 주소를 대입
        //이하 포인터 변수를 배열 처럼 쓸 수 있음을 확인하기
    printf("Address of array[]: %p\n", array);
    printf("Address of parray: %p\n", parray); //line 8번이랑 같음
    printf("\n");
    printf("parray[0] : %d\n", parray[0]); //parray의 첫번쨰 값
    printf("*parray   : %d\n", *(parray+0)); //line 11이랑 같음
    printf("\n");
    printf("*(parray +1): %d\n", *(parray + 1)); //인덱스 [1]의 값
    printf("parray[1]   : %d\n", parray[1]);     //인덱스 [1]의 값
    printf("*(parray +2): %d\n", *(parray + 2)); //인덱스 [2]의 값
    printf("parray[2]   : %d\n", parray[2]);     //인덱스 [2]의 값
    return 0;

}