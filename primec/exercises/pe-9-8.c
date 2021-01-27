#include <stdio.h>
double power(double a, int b);

int main(void)
{
    double x, xpow;
    int n;

    printf("Enter a number and the integer power to which\n");
    printf("the number will be raised. Enter q to quit.\n");
    while (scanf("%lf%d", &x, &n) == 2)
    {
        xpow = power(x, n);
        printf("%.3g to the power %d is %.5g\n", x, n, xpow);
        printf("Enter next pair of numbers or q to quit.\n");
    }
    printf("Hope you enjoyed this power trip --bye!\n");

    return 0;
}

double power(double a, int b)
{
    double pow = 1;
    int i;

    if (b == 0)
    {
        if (a == 0)
        {
            printf("0 to the 0 undefined; using 1 as the value\n");
        }

        pow = 1.0;
    }
    else if (a == 0)
    {
        pow = 0.0;
    }
    else if (b > 0)
    {
        for (i = 1; i <= b; i++)
        {
            pow *= a;
        }
    }
    else
    {
        pow = 1.0 / power(a, -b);
    }

    return pow;
}
