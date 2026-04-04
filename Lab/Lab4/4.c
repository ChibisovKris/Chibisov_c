#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp;
    int num;
    char str[50];
    float fnum;

    printf("Задание 4: Форматированный ввод-вывод\n");

    fp = fopen("formatted.txt", "w");
    if (fp == NULL) {
        printf("Ошибка открытия файла\n");
        return 1;
    }

    printf("Введите число: ");
    scanf("%d", &num);
    printf("Введите строку: ");
    scanf("%s", str);
    printf("Введите дробное число: ");
    scanf("%f", &fnum);

    fprintf(fp, "%d %s %.2f\n", num, str, fnum);

    fclose(fp);
    printf("Данные записаны\n");

    fp = fopen("formatted.txt", "r");
    if (fp == NULL) {
        printf("Ошибка открытия файла\n");
        return 1;
    }

    fscanf(fp, "%d %s %f", &num, str, &fnum);

    printf("Считанные данные\n");
    printf("Число: %d\n", num);
    printf("Строка: %s\n", str);
    printf("Дробное: %.2f\n", fnum);

    fclose(fp);

    return 0;
}