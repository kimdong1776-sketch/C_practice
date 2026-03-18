#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void print_closer(int index, int len,int *arr, int*temp) {
   if (index == len) {//이게 마지막까지 검사를 했단 뜻임 그러고 나서 temp에 1로 마스킹 된 것만 출력하겠다.
      printf("{");
      for (int i = 0; i < len; i++) {
         if (temp[i]== 1) {
            printf("%d ", arr[i]);
         }
      }
      printf("}\n");
      return;
   }
   temp[index] = 1;
   print_closer(index + 1, len, arr, temp);
   temp[index] = 0;
   print_closer(index + 1, len, arr, temp);

}

int main() {

   FILE* f; fopen_s(&f, "in.txt", "r");
   if (f == NULL) {
      exit(1);
   }

   int temp;
   int len = 0;
   int* arr = { 0 };
   int* temp_arr = {0};
   while (fscanf_s(f, "%d", &temp) != EOF) {
      len++;
   }
   fseek(f, 0, SEEK_SET);

   arr = (int*)malloc(sizeof(int)*len);
   temp_arr = (int*)malloc(sizeof(int) * len);
   for (int i = 0; i < len; i++) {
      fscanf_s(f, "%d", &temp);
      arr[i] = temp;
   }

   fclose(f);

   print_closer(0,len, arr, temp_arr);

   
   free(arr);
   free(temp_arr);
}