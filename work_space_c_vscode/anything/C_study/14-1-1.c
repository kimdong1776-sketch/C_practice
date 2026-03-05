#include <stdio.h>

int call_by_value(int n1){
    return n1 * n1;
}

int call_by_reference(int *n1){
    return *n1 * *n1;
}

int main(){
    int num = 3;
    printf("%d", call_by_value(num));
    printf("%d", call_by_reference(&num));


}