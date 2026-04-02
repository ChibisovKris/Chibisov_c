#include <stdio.h>
#include <stdlib.h>  
 
int main(void)
{
    int n;
    printf("Введите длину массива: ");
    scanf("%d", &n);
    int *ptr = calloc(n, sizeof(int)); 
    if (ptr == NULL) {
    printf("ошибка обработки памяти");
    return 1;
    }
        for (int i = 0; i < n; i++)
        {
            printf("%d \n", ptr[i]);
        }

    
    
    free(ptr);
}