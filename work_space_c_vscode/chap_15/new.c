#include <stdio.h>
#include <stdlib.h>

int main(){
    char *fname1 = "old.c";
    char *fname2 = "new.c";

    int result = rename(fname1, fname2);

    if(result == 0){
        printf("파일 %s 가 %s로 수정되었스빈다.\n", fname1, fname2);
    }
    else{
        printf("파일 이름 변경 ㅗ류\n");

   
    }
    return 0;
}