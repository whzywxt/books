#include <stdio.h>
#include <math.h>

void ToUpper(char *);
void ToLower(char *);
void (*pf)(char *);
double (*pdf)(double);

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

    int rect; // 不与struct冲突
    printf("red = %d, orange = %d\n", red, orange);

    // 函数指针
    char mis[] = "Nina Metier";
    pf = ToUpper;
    (*pf)(mis);
    printf("mis=%s\n", mis);

    // 函数指针调用两种方式
    double x;
    pdf = sin;
    x = (*pdf)(1.2);
    printf("%f\n", x); // 调用 sin(1.2)
    x = pdf(1.2);
    printf("%f\n", x); // 同样调用 sin(1.2)

    return 0;
}

void ToUpper(char *str)
{
    while (*str)
    {
        *str = toupper(*str);
        str++;
    }
}
