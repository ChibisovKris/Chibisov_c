#include <stdio.h>
enum Day {
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY,
    SUNDAY
};

struct Event {
    char name[50];
    enum Day day;
};

int main() {
    enum Day today = WEDNESDAY;
    
    switch(today) {
        case MONDAY:
            printf("Понедельник\n");
            break;
        case TUESDAY:
            printf("Вторник\n");
            break;
        case WEDNESDAY:
            printf("Среда\n");
            break;
        case THURSDAY:
            printf("Четверг\n");
            break;
        case FRIDAY:
            printf("Пятница\n");
            break;
        case SATURDAY:
            printf("Суббота\n");
            break;
        case SUNDAY:
            printf("Воскресенье\n");
            break;
    }
    struct Event meeting = {"Встреча", MONDAY};

    switch(meeting.day) {
        case MONDAY:
            printf("Событие: %s\tДень: понедельник", meeting.name);
            break;
        case TUESDAY:
            printf("Событие: %s\tДень: вторник", meeting.name);
            break;
        case WEDNESDAY:
            printf("Событие: %s\tДень: среда", meeting.name);
            break;
        case THURSDAY:
            printf("Событие: %s\tДень: четверг", meeting.name);
            break;
        case FRIDAY:
            printf("Событие: %s\tДень: пятница", meeting.name);
            break;
        case SATURDAY:
            printf("Событие: %s\tДень: суббота", meeting.name);
            break;
        case SUNDAY:
            printf("Событие: %s\tДень: воскресенье", meeting.name);
            break;
    }
    
    

    
    return 0;
}