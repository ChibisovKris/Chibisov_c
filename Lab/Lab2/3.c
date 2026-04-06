#include <stdio.h>
 
struct Date
{
    int day;
    int month;
    int year;
};
struct Person
{
    char * name;
    struct Date birthday;
};
 
int main(void)
{
    struct  Person per[] = {{"Kris", {22, 12, 2008}}, {"Tom", {12, 03, 1995}}, {"Bob", {21, 02, 2012}}};
    int n = sizeof(per)/sizeof(per[0]);
    
    for(int i=0; i<n; i++)
    {
        printf("Name:%s \t Date: %d.%d.%d\n", per[i].name, per[i].birthday.day, per[i].birthday.month, per[i].birthday.year);
    }
    
    for (int i = 0; i < n; i++)
    {
        if (per[i].birthday.year > 2000)
        {
            printf("%s ", per[i].name);
            
        }
        
    }
    


    return 0;
}