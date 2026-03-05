#include<stdio.h>

void add(double*, double, double);
void sub(double*, double, double);
void mul(double*, double, double);
void div(double*, double, double);

int main(){
    char op[4] = {'+', '-', '*', '/'};

    void(*fpary[4])(double*, double, double) = {add, sub, mul, div};

    double m,n,result;
    printf("사칙 연산을 수행할 실수 2개를 입력하세요. >>");
    scanf("%lf %lf", &m, &n);
    for(int i = 0 ; i < 4; i++){
        fpary[i](&result, m , n);
        printf("%.2lf %c %.2lf == %.2lf\n", m, op[i], n, result);
    }
    return 0;
}

void add(double* z, double x, double y){
    *z = x +y;
}
void sub(double* z, double x, double y){
    *z = x -y;
}
void mul(double* z, double x, double y){
    *z = x *y;
}
void div(double* z, double x, double y){
    *z = x /y;
}