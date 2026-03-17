#include <stdio.h>

int main() 
{
    int total_seconds;
    scanf("%d", &total_seconds);

    int hours = (total_seconds / 3600) % 24;
    int minutes = (total_seconds / 60) % 60;
    int seconds = total_seconds % 60;
    printf("%02d:%02d:%02d\n", hours, minutes, seconds);
    return 0;
}