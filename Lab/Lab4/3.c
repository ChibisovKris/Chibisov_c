#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp;
    char str[100];
    int i;

    printf("Задание 3: Работа со строками\n");

    fp = fopen("strings.txt", "w");
    if (fp == NULL) {
        printf("Ошибка открытия файла\n");
        return 1;
    }

    printf("Введите 3 строки:\n");
    for (i = 0; i < 3; i++) {
        printf("Строка %d: ", i + 1);
        fgets(str, 100, stdin);
        fputs(str, fp);
    }

    fclose(fp);
    printf("Строки записаны\n");

    fp = fopen("strings.txt", "r");
    if (fp == NULL) {
        printf("Ошибка открытия файла\n");
        return 1;
    }

    printf("Содержимое файла\n");
    while (fgets(str, 100, fp) != NULL) {
        printf("%s", str);
    }

    fclose(fp);

    return 0;
}