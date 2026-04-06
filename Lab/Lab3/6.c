#include <stdio.h>
#include <stdlib.h>  
 
int main()
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

    int el;
    printf("Добавить элемент по индексу: ");
    scanf("%d", &el);
    
    int a;
    printf("Введите элемент: ");
    scanf("%d", &a);
    
    n = n + 1;
    ptr = (int*)realloc(ptr, n * sizeof(int));
    if (ptr == NULL) {
    printf("ошибка обработки памяти");
    return 1;
    }
    for (int i = n - 1; i > el; i--)
    {
        ptr[i] = ptr[i - 1];

    }
    ptr[el] = a;
    
    
    for (int i = 0; i < n; i++)
        {
            printf("%d \t", ptr[i]);
        }

    
    
    free(ptr);
    ptr = NULL;
}