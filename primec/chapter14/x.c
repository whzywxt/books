#include <stdio.h>

int main(int argc, char const *argv[])
{
    enum spectrum
    {
        red,
        orange,
        yellow,
        green,
        blue,
        violet
    };

    struct rect
    {
        double x;
        double y;
    };

    struct rect rects = {100, 200};

    printf("x = %.2f, y = %.2f\n", rects.x, rects.y);

    int rect;

    printf("red = %d, orange = %d\n", red, orange);

    return 0;
}
