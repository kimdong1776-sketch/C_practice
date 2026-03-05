#include <stdio.h>

int main(){
    int ch;
    int dif = 'a'-'A';
    ch = getchar();
    if((ch < 'A' && ch > 'Z')||(ch < 'a' && ch > 'z')){
        fputs("type error",stdout);
    }
    else{
        if((ch - dif) > 0 ){
            fputc(ch+(dif),stdout);
        }
        else{
            fputc(ch-dif,stdout);

        }
    }
}


