#include <stdio.h>

int main(){
    FILE *f = fopen("sample.txt","w");
    fprintf(f,"ABCDEFGHIJKLMNOPQRSTUVWXYZ");
    fclose(f);

    f = fopen("sample.txt", "r");
    fseek(f, 3, SEEK_SET);
    printf("fseek(fp, 3, SEEK_SET)= %c\n", fgetc(f));

    fseek(f, -1, SEEK_END);
    printf("ㄹㄴㄷ다(ㄹ, -1, ㄴㄷ다)둥) = %c \n", fgetc(f));

    fclose(f);
    return 0; 

}