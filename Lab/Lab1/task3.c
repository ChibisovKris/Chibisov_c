#include <stdio.h>

int main(void)

{
    int a = 10;
    float b = 3.14;
    char c = 'A';
    printf("a = %d, address = %p\n", a, (void*)&a);
    printf("b = %g, address = %p\n", b, (void*)&b);
    printf("c = %c, address = %p\n", c, (void*)&c);
    return 0;
}