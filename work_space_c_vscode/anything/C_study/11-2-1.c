#include <stdio.h>

// int main(){ //1번
//     char c[101] = {0};
//     int len = 0;
//     scanf("%s", c);
//     for(len = 0; c[len] != '\0'; len++){

//     }
//     printf("%d", len);
// }
// int main(){  //2번
//     char c[100] = {0};
//     char c_inverse[100] = {0};
//     int len = 0;
//     scanf("%s", c);

//     for(int i = 0; c[i] != 0; i++){
//         len++;
//     }
    

//     for(int i = 0; i<len ; i++){
//         c_inverse[(len-1)-i] = c[i];        
//     }
//     c_inverse[len] = '\0';
//     printf("%s", c_inverse);
// }
int main(){  //3번
    
    char str[101] = {0};
    int len = 0;
    int max_ascii = 0;
    scanf("%s", str);
    for(int i = 0 ; str[i] != 0 ; i++){
        len++;
    }
    max_ascii = str[0];
    for(int i = 1 ; i < len ; i++){
        if(max_ascii < str[i]){
            max_ascii = str[i];
        }
    }
    printf("max = : %c", max_ascii);
}