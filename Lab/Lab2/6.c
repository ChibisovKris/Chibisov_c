#include <stdio.h>

union Data {
    int i;
    float f;
    char c;
};

enum Type { INT, FLOAT, CHAR };

struct perfect {
    union Data data;
    enum Type type;
};

int main() {
    union Data d;
    d.i = 122;
    d.f = 12.3;
    d.c = 'k';
    printf("d.i = %d\n", d.i);
    printf("d.f = %d\n", d.f);
    printf("d.c = %d\n\n", d.c);
    

    struct perfect cont;
    cont.data.i = 42;
    cont.type = INT;
    printf("type = INT, data.i = %d\n", cont.data.i);
    return 0;
}