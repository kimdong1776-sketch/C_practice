#include <stdio.h>
//----------1번-----------

// void even_det(int *n){
//     int count = 0;
//     int even[10] = {0};
//     printf("짝수 출력: ");
//     for(int i= 0 ; i<10;i++){
//         if(n[i] % 2 == 0){
//             even[count] = n[i];
//             count++;
//         } 
//     }
//     for(int i = 0 ; i < count; i++ ){
//         printf("%d", even[i]);
//         if(i != count -1){
//             printf(", ");
//         }
//     }

// }

// void odd_det(int *n){
    
//     int count = 0;
//     int odd[10] = {0};
//     printf("홀수 출력: ");
//     for(int i= 0 ; i<10;i++){
//         if(n[i]%2){
//             odd[count] = n[i];
//             count++;
//         } 
//     }
//     for(int i = 0 ; i < count; i++ ){
//         printf("%d", odd[i]);
//         if(i != count -1){
//             printf(", ");
//         }
//     }
    
// }

// int main(){
    
//     int num[10] = {0};
//     printf("총 10개의 숫자 입력: \n");
//     for(int i = 0 ; i < 10 ; i++){
//         scanf("%d", &num[i]);
//     }
//     odd_det(num);
//     printf("\n");
//     even_det(num);

// }

//------------------------

// void print_n(int *n){
//     int even[10] = {0};
//     int odd[10] = {0}; 
//     int even_c = 0 , odd_c = 0;
//     for(int i = 0 ; i < 10 ; i++){
//         if(n[i]%2==0){ //짝수
//             even[even_c] = n[i];
//             even_c++;
//         }
//         else{
//             odd[odd_c] = n[i];
//             odd_c++;
//         }
//     }
//     printf("홀수 출력");
//     for(int i = 0; i < odd_c ; i++){
//         printf("%d", odd[i]);
//         if(i != odd_c -1){
//             printf(", ");
//         }

//     }
//     printf("\n짝수 출력");
//     for(int i = 0; i < even_c ; i++){
//         printf("%d", even[i]);
//         if(i != even_c-1){
//             printf(", ");
//         }

//     }
// }

// int main(){
//     int num[10] = {0};
//     printf("총 10개의 숫자 입력: \n");
//     for(int i = 0 ; i < 10 ; i++){
//         scanf("%d", &num[i]);
//     }
//     print_n(num);
// }


//-----------2번-------------
// int main(){
//     int num = 0;
//     int binary[100]= {0};
//     int count = 0;
//     printf("10진수 정수 입력: ");
//     scanf("%d", &num);
//     while(num != 0){
//         if(num % 2 == 0){ //짝수면
//             binary[count] = 0;
//         }
//         else{
//             binary[count] = 1;
//         }
//         num /= 2;
//         count++;
//     }
//     for(int i = count-1; i >= 0 ;i--){
//         printf("%d", binary[i]);
//     }
//     return 0;
// }
//-----------3번-------------

// int main(){
//     int num[10] = {0};
//     int result[10] = {0};
//     int even_c = 0, odd_c =0;
//     printf("총 10거ㅐ의 숫자 입력\n");
//     for(int i = 0 ; i < 10; i++){
//         printf("입력: ");
//         scanf("%d", &num[i]);
//         if(num[i]%2 == 0){
//             result[9-even_c] = num[i];
//             even_c++;
//         }
//         else{
//             result[odd_c] = num[i];
//             odd_c++;
//         }
//     }
//     printf("배열 요소의 출력: ");
//     for(int j = 0 ; j < 10 ; j++){
//         printf("%d ", result[j]);
//     }
//     return 0;
        
// }

//-----------4번-------------
// int main(){
//     char str[101] = {0};
//     int len = 0;
//     printf("문자열 입력: ");
//     scanf("%s", str);
//     for(int i = 0 ; str[i] != 0; i++){
//         len++;
//     }
//     for(int i = 0; i < len ; i++){
//         if(str[i] != str[len-1-i]){
//             printf("회문이 아닙니다.");
//             return 0;
//         }
//     }
//     printf("회문입니다.");
//     return 0;
// }

//----------5번-------------
// void buble_sort(int *n, int len){
//     int temp = 0;
//     for(int j = 0 ; j < len-1; j++){//전체 sort 시키는거
//         for(int  i = 0 ; i < len-1-j; i++){ //하나 sort시키는거
//             if(n[i]>n[i+1]){
//                 temp = n[i+1];
//                 n[i+1] = n[i];
//                 n[i] = temp;
//             }
//         }
//     }
// }

// int main(){
//     int num[101] = {0};
//     int len = 0;
//     int i = 0;
//     printf("0을 입력하면 입력 종료");
//     do{
//         scanf("%d", &num[i]);
//         if(num[i] == 0){
//             break;
//         }
//         len ++;
//         i++;
//     }while(i < 100);
//     printf("아래 숫자 입력\n");
//     buble_sort(num, len);
//     for(int i = 0 ; i < len ; i++){
//         printf("%d ", num[i]);
//     }
// }

void DesSort(int *n,int len){
    int temp = 0;
    printf("\n\n");
    printf("내림차순 정렬: ");
    for(int i = 0; i < len-1;i++){
        for(int j = len-1-i ; j>0 ;j--){
            if(n[j] > n[j-1]){
                temp = n[j];
                n[j] = n[j-1];
                n[j-1] = temp;
            }
        } 
    }
}

int main(int argc, char* argv[]){
    int num[7] = {0};
    int i = 0;
    
    do{
        printf("입력: " );
        scanf("%d", &num[i]);
        i++;
    }while(i < 7);

    DesSort(num, sizeof(num)/sizeof(int));
    for(int j = 0 ; j < 7 ; j++){
        printf("%d ", num[j]);
    }
}