#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp;

    printf(" Задание 1: Открытие и закрытие файла \n");

       fp = fopen("test.txt", "w");

        if (fp == NULL) {
        printf(" Ошибка: не удалось открыть файл \n");
        return 1;
    }

    printf(" Файл успешно открыт \n");

    fclose(fp);
    printf(" Файл закрыт \n");

    return 0;
}