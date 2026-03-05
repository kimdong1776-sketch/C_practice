#include <stdio.h>

int main(){

int m =1, n=5;

printf("%d %d\n", m++, --n);
printf("%d %d\n", m, n);
printf("%d %d\n", m--, ++n);
printf("%d %d\n", m, n);

return 0;
}