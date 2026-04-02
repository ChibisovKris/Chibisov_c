#include <stdio.h>
 
struct Student
{
    char * name;
    int age;
    float gpa;
} S1;     
 
int main(void)
{
    S1.age = 17;
    S1.name = "Chibisov Kristian";
    S1.gpa = 7.8;
    printf("Name: %s\nAge: %d\nGpa= %f\n", S1.name, S1.age, S1.gpa);

    struct Student S2;
    scanf("%s %d %f", &S2.name, &S2.age, &S2.gpa);
    return 0;
}