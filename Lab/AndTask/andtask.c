#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

typedef struct {
    char name[100];
    int age;
    float height;
    int birthyear;
} Person;

Person *people = NULL;
int count = 0;
int norm = 0;

int valid_name(const char *name) {
    for (int i = 0; name[i]; i++)
        if (!isalpha(name[i]) && name[i] != ' ')
            return 0;
    return 1;
}

void add_person() {
    Person newperson;
    char name[100];
    
    printf("Введите имя: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';
    
    if (!valid_name(name)) {
        printf("Ошибка: имя должно содержать только буквы.\n");
        return;
    }
    
    printf("Введите возраст: ");
    scanf("%d", &newperson.age);
    if (newperson.age <= 0) {
        printf("Ошибка: возраст должен быть положительным.\n");
        return;
    }
    
    printf("Введите рост: ");
    scanf("%f", &newperson.height);
    if (newperson.height <= 0) {
        printf("Ошибка: рост должен быть положительным.\n");
        return;
    }
    
    printf("Введите год рождения: ");
    scanf("%d", &newperson.birthyear);
    while(getchar() != '\n');
    
    strcpy(newperson.name, name);
    
    if (count >= norm) {
        norm = (norm == 0) ? 2 : norm * 2;
        Person *temp = realloc(people, norm * sizeof(Person));
        if (!temp) {
            printf("Ошибка выделения памяти!\n");
        return;
        }
    people = temp;
    }
    people[count++] = newperson;
    printf("Добавлен.\n");
}

void print_all() {
    for (int i = 0; i < count; i++) {
        printf("%s  Возраст: %d  Рост: %.2f  Год рождения: %d\n", people[i].name, people[i].age, people[i].height, people[i].birthyear);
    }
}

void sort_by_name() {
    if (count == 0) {
        printf("Нет данных для сортировки.\n");
        return;
    }

    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - 1 - i; j++) {
            if (strcmp(people[j].name, people[j + 1].name) > 0) {
                Person temp = people[j];
                people[j] = people[j + 1];
                people[j + 1] = temp;
            }
        }
    }

    printf("Отсортировано по имени.\n");
}

void sort_by_age() {
    if (count == 0) {
        printf("Нет данных для сортировки.\n");
        return;
    }
    
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - 1 - i; j++) {
            if (people[j].age > people[j + 1].age) {
                Person temp = people[j];
                people[j] = people[j + 1];
                people[j + 1] = temp;
            }
        }
    }
    
    printf("Отсортировано по возрасту.\n");
}

void statistics() {
    if (count == 0) {
        printf("Нет данных.\n");
        return;
    }
    float sumage = 0;
    float maxheight = people[0].height;
    for (int i = 0; i < count; i++) {
        sumage += people[i].age;
        if (people[i].height > maxheight)
            maxheight = people[i].height;
    }
    printf("Средний возраст: %.2f\n", sumage / count);
    printf("Максимальный рост: %.2f\n", maxheight);
}

void search_by_name() {
    char name[100];
    printf("Введите имя: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';
    
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(people[i].name, name) == 0) {
            printf("Найден: %s  Возраст: %d  Рост: %.2f  Год рождения: %d\n", people[i].name, people[i].age, people[i].height, people[i].birthyear);
            found = 1;
        }
    }
    if (!found) printf("Не найден.\n");
}

void search_by_age() {
    int min, max;
    printf("Введите мин возраст: ");
    scanf("%d", &min);
    printf("Введите макс: ");
    scanf("%d", &max);
    
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (people[i].age >= min && people[i].age <= max) {
            printf("%s  Возраст: %d  Рост: %.2f  Год рождения: %d\n", people[i].name, people[i].age, people[i].height, people[i].birthyear); 
            found = 1;
        }
    }
    if (!found) printf("Не найден.\n");
}

void save_binary() {
    FILE *f = fopen("data.bin", "wb");
    if (!f) {
        printf("Ошибка открытия файла.\n");
        return;
    }
    fwrite(&count, sizeof(int), 1, f);
    fwrite(people, sizeof(Person), count, f);
    fclose(f);
    printf("Сохранено %d записи.\n", count);
}

void load_binary() {
    FILE *f = fopen("data.bin", "rb");
    if (!f) {
        printf("Ошибка открытия файла.\n");
        return;
    }
    int new_count;
    fread(&new_count, sizeof(int), 1, f);
    Person *new_people = malloc(new_count * sizeof(Person));
    if (!new_people) {
    printf("Ошибка выделения памяти.\n");
    fclose(f);
    return;
    }
    fread(new_people, sizeof(Person), new_count, f);
    fclose(f);
    
    free(people);
    people = new_people;
    count = new_count;
    norm = new_count;
    printf("Загружено %d записи.\n", count);
}

void exitprog() {
    free(people);
    printf("До свидания.\n");
    exit(0);
}

void (*menu[])() = {
    add_person,
    print_all,
    sort_by_name,
    sort_by_age,
    statistics,
    search_by_name,
    search_by_age,
    save_binary,
    load_binary,
    exitprog
};

int main() {
    int choice;
    
    do {
        printf("\n=== МЕНЮ ===\n");
        printf("1. Добавить человека\n");
        printf("2. Вывести всех\n");
        printf("3. Сортировать по имени\n");
        printf("4. Сортировать по возрасту\n");
        printf("5. Статистика\n");
        printf("6. Поиск по имени\n");
        printf("7. Поиск по диапазону возраста\n");
        printf("8. Сохранить\n");
        printf("9. Загрузить\n");
        printf("10. Выход\n");
        printf("Выбор: ");
        
        scanf("%d", &choice);
        while(getchar() != '\n');
        
        if (choice >= 1 && choice <= 10) {
            menu[choice-1]();
        } else {
            printf("Неправильный ввод.\n");
        }
    } while (1);
    
    return 0;
}