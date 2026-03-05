#include <stdio.h>
#include <ctype.h>
#include <string.h>

/*
문제: "한 줄에 있는 가장 긴 연속 숫자 개수 세기"
문자열(최대 100자)이 입력된다. 이 중에서 한 줄에 연속해서 등장하는 최대 숫자(0~9)의 개수를 출력하는 프로그램을 작성하라.

입력 예시
ab1234cd567ef89

출력 예시
4
(1234가 연속으로 4자리임)
*/

int main(void)
{
   char input[101];
   int number_length_max = 0;
   int number_length = 0;
   int cont =0;
    
   scanf("%s", input);

   for (int i = 0; i < strlen(input); i++)
   {
      if (isdigit(input[i]))
      {
         number_length++;
         cont++;
      }
      else if(cont != 0 && number_length_max < number_length)
      {
         number_length_max = number_length;
         number_length = 0;
         cont = 0;
      }
      else
      {
         number_length = 0;
         cont = 0;
      }
      
   }

   if(cont != 0 && number_length_max < number_length)
      printf("%d", number_length);
   else
      printf("%d", number_length_max);
   return 0;
}