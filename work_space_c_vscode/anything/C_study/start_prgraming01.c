#include<stdio.h>

void P1(){
    int num;
    scanf("%d", &num);
    printf("%#x", num);
}
//-------------------------------------------
void print_99dan(int n1, int n2);  

void P2(){
    int  num1, num2;
    scanf("%d %d", &num1, &num2);
    num1 > num2 ? print_99dan(num2, num1) : print_99dan(num1, num2);
    
}
void print_99dan(int n1, int n2){
    int temp = n1;
    for(int i = 1 ; i < 10 ; i++){
        for(;n1 < (n2 + 1) ; n1++){
            printf("%d * %d = %d\t", n1, i, n1*i);
        }
        n1 = temp;
        printf("\n");
    }
    
}
//-------------------------------------------
int GCD(int n1, int n2);
void P3(){
    int num1, num2;
    scanf("%d %d", &num1, &num2);
    printf("%d",GCD(num1, num2));
}
int GCD(int n1, int n2){
    if(n2 == 0){
        return n1;
    }
    else{
        return GCD(n2, n1 % n2);
    }
    

}
//-------------------------------------------
void P4(){
    int money = 3500;
    int food[3] = {500, 700, 400};
    for(int i = 1; i * food[0] < money; i++){
        for(int j = 1; j* food[1] < money; j++){
            for(int k = 1; k*food[2] < money; k++){
                if(k*food[2] + j*food[1] + i*food[0] == money){
                    printf("크림빵%d개, 새우깡 %d개, 콜 라 %d개\n", i, j , k);
                }
            }
        }
    }
}
//-------------------------------------------
void P5(){
    int count = 0;
    int prime = 1;
    for(int i = 2; count < 10; i++){      
        prime = 1;  
        for(int j = 2; j*j <= i ;j++){
            if(i%j == 0){ 
                prime = 0;
                break;
            }
        }
        if(prime == 1){
            printf("%d ", i);
            count++;
        }

    }   
}
//-------------------------------------------
void P6(){
    int second;
    int h=0, m=0;
    scanf("%d", &second);
    h = second / 3600;
    second = second % 3600;
    
    m = second / 60;
    second = second % 60;

    printf("[h:%d, m: %d, s: %d]",h,m,second);

}
//-------------------------------------------
void P7(){
    int num=0, pow_data = 1, i;
    scanf("%d", &num);
    for(i = 0 ; pow_data<=num; i++){
        pow_data = 2<<i;
    }
    printf("공식을 만족하는 k의 최댓값은 %d", i-1);
}
//-------------------------------------------
int pow_d(int count);

void P8(){
    int num;
    scanf("%d", &num);
    printf("%d",pow_d(num));
}
int pow_d(int count){
    if(count == 1){
        return 2;
    }
    else{
        return 2*pow_d(count-1);
    }
    
}

int main(){
    P1();
    P2();
    P3();
    P4();
    P5();
    P6();
    P7();
    P8();
}