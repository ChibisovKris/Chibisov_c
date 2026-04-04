#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Person {
    char name[50];
    int age;
};

void writePeople() {
    FILE *fp;
    struct Person p;
    int n, i;

    printf("Сколько человек записать? ");
    scanf("%d", &n);
    getchar(); 

    fp = fopen("people_db.bin", "ab"); 
    if (fp == NULL) {
        printf("Ошибка открытия файла\n");
        return;
    }

    for (i = 0; i < n; i++) {
        printf("\nЧеловек %d\n", i + 1);
        printf("Имя: ");
        fgets(p.name, 50, stdin);
        p.name[strcspn(p.name, "\n")] = '\0'; 

        printf("Возраст: ");
        scanf("%d", &p.age);
        getchar(); 

        fwrite(&p, sizeof(struct Person), 1, fp);
    }

    fclose(fp);
    printf("\nДанные записаны\n");
}

void readPeople() {
    FILE *fp;
    struct Person p;
    int count = 0;

    fp = fopen("people_db.bin", "rb");
    if (fp == NULL) {
        printf("Файл не найден\n");
        return;
    }

    printf("\nСписок людей:\n");
    printf("| %-5s   | %-20s | %-10s |\n", "№", "Имя", "Возраст");

    while (fread(&p, sizeof(struct Person), 1, fp) == 1) {
        count++;
        printf("| %-5d | %-20s | %-10d |\n", count, p.name, p.age);
    }

    if (count == 0) {
        printf("Файл пуст\n");
    }

    fclose(fp);
}

void showMenu() {
    printf("ФАЙЛОВАЯ БАЗА ЛЮДЕЙ\n");
    printf("1. Добавить людей\n");
    printf("2. Показать всех\n");
    printf("0. Выход\n");
    printf("Выбор: ");
}

void deleteData() {
    if (remove("people_db.bin") == 0) {
        printf("Файл с данными удалён\n");
    } else {
        printf("Файл не найден или уже удалён\n");
    }
}

int main() {
    int choice;

    printf("Задание 12: Файловая база людей\n");

    do {
        showMenu();
        scanf("%d", &choice);
        getchar(); 

        switch(choice) {
            case 1: writePeople(); 
            break;
            case 2: readPeople(); 
            break;
            case 0: deleteData();
            printf("До свидания!\n"); 
            break;
            default: printf("Неверный выбор\n");
        }
    } while (choice != 0);

    return 0;
}