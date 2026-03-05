/*
문제: "한 줄에 있는 가장 긴 연속 숫자 개수 세기"
문자열(최대 100자)이 입력된다. 이 중에서 한 줄에 연속해서 등장하는 최대 숫자(0~9)의 개수를 출력하는 프로그램을 작성하라.

입력 예시
ab1234cd567ef89

출력 예시
4
(1234가 연속으로 4자리임)
*/

#include <stdio.h>

int main(void) {
    char dkd[101] = {0};
    int len = 0;
    int count =0;
    int max = 0;
    int temp =0;
    scanf("%s", dkd);
    while (dkd[len] != '\0') len++;
    
    for(int i = 0;i<len;i++){
        
        if ((dkd[i] >= '0' && dkd[i] <= '9')){
            
            for(int c = i;(dkd[c] >= '0' && dkd[c] <= '9');c++){
                count++;
            }
            temp = count;
            count = 0;
        }

        else
            continue;

        if (temp > max) max = temp;
    }

    printf("%d",max);
    return 0;

}