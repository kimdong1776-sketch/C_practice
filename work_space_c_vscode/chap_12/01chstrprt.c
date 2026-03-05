#include <stdio.h>

int main(){
    char ch = 'A';
    printf("%c %d\n", ch, ch);

    char java[] = {'J','A','V','A', '\0'};
    printf("%s", java);

    char py[] = "Python";
    printf("%s\n", py);

    char csharp[5] = "C#";
    puts(csharp);

    printf("%c %c\n", csharp[0], csharp[1]);

    return 0;
}