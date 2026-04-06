#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *hor;
    long size;

    printf("Задание 10: Размер файла\n");

    hor = fopen("size_test.txt", "w");
    if (hor == NULL) {
        printf("Ошибка создания файла\n");
        return 1;
    }

    fprintf(hor, "Hello, World!\n");
    fprintf(hor, "This is a test file.\n");
    fclose(hor);

    hor = fopen("size_test.txt", "r");
    if (hor == NULL) {
        printf("Ошибка открытия файла\n");
        return 1;
    }

    fseek(hor, 0, SEEK_END);
    size = ftell(hor);
    fclose(hor);

    printf("Размер файла: %ld байт\n", size);

    return 0;
}