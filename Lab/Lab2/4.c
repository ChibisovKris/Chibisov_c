#include <stdio.h>

struct Rectangle {
    double width;
    double height;
};

double calcS1(struct Rectangle rect) {
    return rect.width * rect.height;
}

double calcP1(struct Rectangle rect) {
    return 2 * (rect.width + rect.height);
}

double calcS2(struct Rectangle *rect) {
    return rect->width * rect->height;
}

double calcP2(struct Rectangle *rect) {
    return 2 * (rect->width + rect->height);
}

int main() {
    struct Rectangle rect = {5.0, 3.0};
    printf("  Ширина: %.2f\n", rect.width);
    printf("  Высота: %.2f\n", rect.height);
    printf("  Площадь: %.2f\n", calcS1(rect));
    printf("  Периметр: %.2f\n", calcP1(rect));
    printf("\n");
    printf("  Ширина: %.2f\n", rect.width);
    printf("  Высота: %.2f\n", rect.height);
    printf("  Площадь: %.2f\n", calcS2(&rect));
    printf("  Периметр: %.2f\n", calcP2(&rect));
    printf("\n");
    

}
