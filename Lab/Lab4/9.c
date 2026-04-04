#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *temp;
    char str[] = "ABCDEFGHIJ";
    char term;
    int hor;

    printf("Задание 9: Позиционирование в файле\n");

    temp = fopen("seek.txt", "w");
    if (temp == NULL) {
        printf("Ошибка открытия файла\n");
        return 1;
    }

    fputs(str, temp);
    fclose(temp);

    temp = fopen("seek.txt", "r");
    if (temp == NULL) {
        printf("Ошибка открытия файла\n");
        return 1;
    }

    printf("Введите позицию (0-9): ");
    scanf("%d", &hor);

    if (hor < 0 || hor >= 10) {
        printf("Неверная позиция\n");
        fclose(temp);
        return 1;
    }

    fseek(temp, hor, SEEK_SET);

    printf("Данные с позиции %d: ", hor);
    while ((term = getc(temp)) != EOF) {
        putchar(term);
    }

    fclose(temp);

    return 0;
}