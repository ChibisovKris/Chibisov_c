#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp;
    char ch;

    printf("++ Задание 2: Посимвольная запись и чтение ++\n");

    fp = fopen("chars.txt", "w");
    if (fp == NULL) {
        printf("Ошибка открытия файла\n");
        return 1;
    }

    printf("Введите строку для записи (Enter для завершения):\n");
    while ((ch = getchar()) != '\n') {
        putc(ch, fp);
    }

    fclose(fp);
    printf("++ Данные записаны ++\n");

    fp = fopen("chars.txt", "r");
    if (fp == NULL) {
        printf("Ошибка открытия файла\n");
        return 1;
    }

    printf("++ Содержимое файла: ++\n");
    while ((ch = getc(fp)) != EOF) {
        putchar(ch);
    }
    printf("\n");

    fclose(fp);

    return 0;
}