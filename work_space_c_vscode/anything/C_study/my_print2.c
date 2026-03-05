#include<stdio.h>
#include<stdarg.h>

void print_d(int n){
    if(n < 0){
        putchar('-');
        n = -n;
    }
    if(n / 10 != 0){
        print_d(n/10);
    }
    putchar((char)(n%10)+'0');
}

int my_print(char *format, ...){
    va_list ap;
    va_start(ap, format);
    int count = 0 ;
    while(*format != '\0'){
        if(*format == '%'){
            format++;
            if(*format == 'd'){
                int num = va_arg(ap, int);
                print_d(num);
            }
            else if(*format == 'c'){
                int ch = va_arg(ap, int);
                putchar(ch);
            }
            else if(*format == 's'){
                char *ch = va_arg(ap, char*);
                while(*ch != '\0'){
                    putchar(*ch);
                    ch++;
                }
            }
        }
        else{
            putchar(*format);
        }
        count++;
        format++;
    }
    return count;
}

int main(){
    int age = -20;
    my_print("%d  안녕", age);

}