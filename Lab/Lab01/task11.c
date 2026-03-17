#include <stdio.h>

int main(void)

{
    int x;
    printf("Enter number: ");
    scanf("%d", &x);
    printf("Last digit of the number %d is %d", x, x % 10);
    return 0;
}