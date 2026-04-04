#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp;
    char str[200];

    printf("Задание 5: Ввод с клавиатуры и запись в файл\n");

    printf("Введите строку: ");
    fgets(str, 200, stdin);

    fp = fopen("keyboard.txt", "w");
    if (fp == NULL) {
        printf("Ошибка открытия файла\n");
        return 1;
    }

    fputs(str, fp);
    fclose(fp);

    printf("Строка записана в файл\n");

    fp = fopen("keyboard.txt", "r");
    if (fp == NULL) {
        printf("Ошибка открытия файла\n");
        return 1;
    }

    printf("Содержимое файла:\n");
    fgets(str, 200, fp);
    printf("%s", str);

    fclose(fp);

    return 0;
}