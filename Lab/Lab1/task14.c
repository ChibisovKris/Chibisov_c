#include <stdio.h>

int main(void)
{
    int a;
    int b;
    int c;
    printf("a address = %p\n", (void*)&a);
    printf("b address = %p\n", (void*)&b);
    printf("c address = %p\n", (void*)&c);
    printf("a-b = %p\nb-c = %p\na-c = %p\n", (void*)&a - (void*)&b, (void*)&b - (void*)&c, (void*)&a - (void*)&c);
    /*Разница между переменными 4 байта т.к именно столько занимает переменная типа int 
    (От начала одной переменной до начала другой - 1 переменная - 4 байта)*/
    return 0;
}