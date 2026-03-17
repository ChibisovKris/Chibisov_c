#include <stdio.h>

int main(void)

{
    int x;
    printf("Enter x: ");
    scanf("%d", &x);
    printf("Expression value x^2+2x+1 = %d\n", x*x+2*x+1);
    printf("Expression value (x+1)^2-(x-1)^2 = %d\n", (x+1)*(x+1)-(x-1)*(x-1));
    return 0;
}