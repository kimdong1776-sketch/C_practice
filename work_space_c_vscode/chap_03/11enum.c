#include<stdio.h>

int main(){

    enum DAY {SUN,MON,TUE,WED,THU,FRI,SAT};
    printf("%d %d\n",SUN,THU);

    enum SHAPE {POINT, LINE, TRI= 3, RECT, OCTA= 8, CIRCLE};
    printf("LINE: %d, RECT: %d, CIRCLE: %d\n", LINE, RECT, CIRCLE);
    
    enum pl{ c= 1972, cpp= 1983, java= 1995, csharp= 2000};
    printf("c: %d, cpp: %d, java: %d\n", c, cpp, java);
    
    return 0;
}