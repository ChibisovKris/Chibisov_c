#include <stdio.h>
#include <stdlib.h>  
 
typedef struct 
{
    char name[100];
    int age;
}Student;

int main()
{
    int n;
    printf("Введите колво студентов: ");
    scanf("%d", &n);

    Student *arr = (Student*)malloc(n * sizeof(Student));
    if (arr == NULL) {
    printf("ошибка обработки памяти");
    return 1;
    }
    for (int i = 0; i < n; i++)
    {
        printf("Введите %d имя: ", i + 1);
        scanf("%s", arr[i].name);
        
    }
    for (int i = 0; i < n; i++)
    {
       printf("Введите возраст %s: ", arr[i].name);
       scanf("%d", &arr[i].age);
    }
    
    for (int i = 0; i < n; i++) {
        printf("Name: %s Age: %d\n", arr[i].name, arr[i].age);
    }
    char * namemax;
    int a = arr[0].age;
    for (int i = 1; i < n; i++)
    {
        if (a < arr[i].age)
        {
            a = arr[i].age;
             namemax = arr[i].name;
        }
        
    }
    printf("Nameoldest: %s", namemax);



    free(arr);
    arr = NULL;
}