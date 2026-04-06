#include <stdio.h>
#include <stdlib.h>  
int minel(int *ptr, int n){
    int min = *ptr;
    for (int i = 1; i < n; i++)
    {
        if (min > ptr[i])
        {
            min = ptr[i];
        }
        
    }
    return min;
}
int maxel(int *ptr, int n){
    int max = *ptr;
    for (int i = 1; i < n; i++)
    {
        if (max < ptr[i])
        {
            max = ptr[i];
            
        }
        
    }
    return max;
}
int sum(int *ptr, int n){
    int sum = ptr[0];
    for (int i = 1; i < n; i++)
        {
        sum = sum + ptr[i];
        }
    return sum;


}
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
    
    
    
    printf("Min = %d\n", minel(ptr, n));
    printf("Max = %d\n", maxel(ptr, n));
    printf("Sum = %d\n", sum(ptr, n));

    
    
    free(ptr);
}