#include <stdio.h>
#include <stdlib.h>  
 
int main(void)
{
    int n;
    printf("Введите длину массива: ");
    scanf("%d", &n);
    int *ptr = malloc(n * sizeof(int)); 
    if (ptr == NULL) {
    printf("ошибка обработки памяти");
    return 1;
    }
    for (int i = 0; i < n; i++)
    {
        printf("Введите %d значение: ", i + 1);
        scanf("%d", &ptr[i]);

    }
    int m;
    printf("Введите новую длину массива: ");
    scanf("%d", &m);
    ptr = (int*)realloc(ptr, m * sizeof(int));
    if (ptr == NULL) {
    printf("ошибка обработки памяти");
    return 1;
    }
    for (int i = n; i < m; i++)
    {
        printf("Введите %d значение: ", i + 1);
        scanf("%d", &ptr[i]);

    }
    for (int i = 0; i < m; i++)
        {
            printf("%d \n", ptr[i]);
        }
    ptr = (int*)realloc(ptr, n * sizeof(int)); 
    if (ptr == NULL) {
    printf("ошибка обработки памяти");
    return 1;
    }
    
    
    free(ptr);
    ptr = NULL;
}