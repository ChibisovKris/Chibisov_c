#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp;
    int arr[10] = {1, 2, 3, 4, 5, 10, 12, 14, 16, 18};
    int read_arr[5];
    int i;

    printf("Задание 6: Бинарные файлы\n");

    fp = fopen("binary.bin", "wb");
    if (fp == NULL) {
        printf("Ошибка открытия файла\n");
        return 1;
    }

    fwrite(arr, sizeof(int), 10, fp);
    fclose(fp);

    printf("Массив записан в бинарный файл\n");

    fp = fopen("binary.bin", "rb");
    if (fp == NULL) {
        printf("Ошибка открытия файла\n");
        return 1;
    }

    fread(read_arr, sizeof(int), 10, fp);
    fclose(fp);

    printf("Считанные данные:\n");
    for (i = 0; i < 10; i++) {
        printf("%d ", read_arr[i]);
    }
    printf("\n");

    return 0;
}