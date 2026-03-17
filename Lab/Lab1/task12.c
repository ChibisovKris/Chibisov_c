#include <stdio.h>

int main(void)
{
    int x;
    printf("Enter number: ");
    scanf("%d", &x);
    printf("How many hundreds in the number %d - %d\n", x, (x / 100) % 10);
    printf("How many tens in the number %d - %d\n", x, (x /10) % 10);
    printf("How many units in the number %d - %d\n", x, x % 10);
    return 0;
}