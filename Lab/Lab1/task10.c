#include <stdio.h>

int main(void)

{
    int a = 5;
    int b = 10;
    int c;
    printf("a = %d, b = %d\n", a, b);
    c = a;
    a = b;
    b = c;
    printf("After change a = %d, b = %d\n", a, b);
    return 0;
}