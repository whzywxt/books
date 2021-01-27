#include <stdio.h>

double min(double x, double y);

int main(void)
{
    double x, y;

    printf("Enter two numbers (q to quit): \n");
    while (scanf("%lf %lf", &x, &y) == 2)
    {
        printf("The smaller number is %f.\n", min(x, y));
        printf("Next two values (q to quit): \n");
    }

    printf("Bye!\n");

    return 0;
}

double min(double a, double b)
{
    return a < b ? a : b;
}
