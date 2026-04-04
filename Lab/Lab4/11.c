#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *hor;
    int temp; 

    printf("Задание 11: Проверка конца файла и ошибок\n");

    hor = fopen("eof_test.txt", "w");
    if (hor == NULL) {
        printf("Ошибка создания файла\n");
        return 1;
    }

    fprintf(hor, "Test");
    fclose(hor);

    hor = fopen("eof_test.txt", "r");
    if (hor == NULL) {
        printf("Ошибка открытия файла\n");
        return 1;
    }

    printf("Чтение файла\n");
    while ((temp = getc(hor)) != EOF) {
        putchar(temp);
    }
    printf("\n");

    if (feof(hor)) {
        printf("Достигнут конец файла\n");
    }

    if (ferror(hor)) {
        printf("Ошибка при чтении\n");
    } else {
        printf("Ошибок нет\n");
    }

    fclose(hor);

    return 0;
}
