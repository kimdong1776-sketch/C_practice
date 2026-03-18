#include <stdio.h>

void trans_time(int * H, int * Ml){

}


int main(){
    int OH, OM;
    int AH, AM = 0;
    scanf("%d %d", &OH, &OM);
    AH = OH;
    for( ; AM < 45; OM--){
        AM++;
        if(OM == 0){
            OM = 60;
            AH--;
        }
        if(AH == 0){
            AH = 24;
        }
    }
    AM = OM;

    printf("%d %d", AH, AM);
}
