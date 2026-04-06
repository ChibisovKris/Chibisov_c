#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("Введите длину массива: ");
    scanf("%d", &n);
    int *arr = malloc(n * sizeof(int));
    if (arr == NULL) {
    printf("ошибка обработки памяти");
    return 1;
    }
    for (int i = 0; i < n; i++)
    {
        printf("Введите %d значение: ", i + 1);
        scanf("%d", &arr[i]);

    }
    int choice, index, a;

    do {
        printf("\n=== МЕНЮ ===\n");
        printf("1. Добавить элемент\n");
        printf("2. Удалить элемент\n");
        printf("3. Вывод списка\n");
        printf("4. Изменить размер массива\n");
        printf("5. Выход\n");
        printf("Выбор: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Введите значение: ");
                scanf("%d", &a);
                n++;
                arr = realloc(arr, n * sizeof(int));
                    if (arr == NULL) {
                    printf("ошибка обработки памяти");
                    return 1;
                    }
                arr[n - 1] = a;
                printf("Добавлено!\n");
                break;

            case 2:
                printf("Введите индекс (0-%d): ", n - 1);
                scanf("%d", &index);
                for (int i = index; i < n - 1; i++) {
                    arr[i] = arr[i + 1];
                }
                n--;
                arr = realloc(arr, n * sizeof(int));
                    if (arr == NULL) {
                    printf("ошибка обработки памяти");
                    return 1;
                    }
                break;

            case 3:
                printf("Список: ");
                for (int i = 0; i < n; i++) {
                    printf("%d ", arr[i]);
                }
                break;

            case 4:
                printf("Введите новый размер: ");
                scanf("%d", &n);
                arr = realloc(arr, n * sizeof(int));
                    if (arr == NULL) {
                    printf("ошибка обработки памяти");
                    return 1;
                    }
                break;

            case 5:
                printf("До свидания!\n");
                break;

            default:
                printf("Неверный выбор!\n");
        }
    }while (choice != 5);

    free(arr);
    arr = NULL;
    return 0;
}