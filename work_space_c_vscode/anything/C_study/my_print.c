#include <stdio.h>
#include <stdarg.h> // 가변 인자를 위한 필수 헤더

// 숫자를 문자열로 바꿔서 찍어주는 도우미 함수 (재귀함수)
void print_decimal(int n) {
    if (n < 0) {
        putchar('-');
        n = -n; // 양수로 바꿈
        // 주의: INT_MIN 처리는 생략된 간단 버전입니다.
    }
    
    if (n / 10 != 0) {
        print_decimal(n / 10); // 앞자리부터 찍기 위해 재귀 호출
    }
    putchar((n % 10) + '0'); // 숫자를 아스키 문자('0'~'9')로 변환
}

// 우리가 직접 만든 printf
int my_printf(const char *format, ...) {
    va_list ap; // 가변 인자 목록 포인터 (Argument Pointer)
    int count = 0; // 출력된 글자 수 (printf는 원래 글자 수를 리턴함)

    va_start(ap, format); // 가변 인자 읽기 시작!

    while (*format != '\0') {
        if (*format == '%') {
            format++; // '%' 다음 글자를 봄 (서식 지정자)
            
            if (*format == 'd') {
                int i = va_arg(ap, int); // 인자 목록에서 int 하나 꺼냄
                print_decimal(i);
            } 
            else if (*format == 'c') {
                int c = va_arg(ap, int); // char도 내부적으론 int로 취급
                putchar(c);
            } 
            else if (*format == 's') {
                char *str = va_arg(ap, char*); // 인자 목록에서 주소(포인터) 꺼냄
                while (*str != '\0') {
                    putchar(*str);
                    str++;  
                }
            }
        } 
        else {
            // '%'가 아니면 그냥 있는 그대로 출력
            putchar(*format);
        }
        count++;
        format++; // 다음 글자로 이동
    }

    va_end(ap); // 가변 인자 읽기 종료 (뒷정리)
    return count;
}

int main() {
    int age = 20;
    
    // 직접 만든 printf 테스트
    my_printf("Hello! I am %d years old.\n", age);
    my_printf("Character: %c, String: %s\n", 'A', "Coding is Fun");
    
    return 0;
}