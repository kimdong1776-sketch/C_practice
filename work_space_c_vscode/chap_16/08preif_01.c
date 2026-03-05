#include <stdio.h>

// #define WINDOWS

#ifdef WINDOWS
typedef int my_int;
#elif defined MAC
typedef long my_int;
#elif defined LINUX
typedef long long my_int;
#else 
typedef short my_int;
#endif

int main(){
    // my_int n = 17;
#ifdef WINDOWS
    printf("windows 변수 크기 : %zu, 저장 값: %d\n", sizeof(n), n);
#elif defined MAC
    printf("MAC 변수 크기: %zu, 저장 값: %ld\n", sizeof(n), n);
#endif 
    return 0;

}