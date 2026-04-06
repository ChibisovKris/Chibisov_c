#include <stdio.h>
 
struct Student
{
    int age;
    char * name;
    float gpa;
} ;
 
int main(void)
{
    struct Student people[] = { {17, "Kris", 1.0}, {18, "Bob", 6.5}, {16, "Alice", 7.8}, {16, "Sam", 9.0}, {19, "Tom", 3.5}};
    int n = sizeof(people)/sizeof(people[0]);
    for(int i=0; i<n; i++)
    {
        printf("Name:%s \t Age: %d \t Gpa: %.1f\n", people[i].name, people[i].age, people[i].gpa);
    }
    float a = people[0].gpa;
    char *s = people[0].name;
    for (int i = 1; i < n; i++)
    {
        if (a < people[i].gpa)
        {
            a = people[i].gpa;
            s = people[i].name;
        }
        
    }
    while (*s)
    {
        printf("%c", *s);
        s++;
    }
    
    return 0;
}