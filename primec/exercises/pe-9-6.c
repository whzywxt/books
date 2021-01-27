#include <stdio.h>
void sort_of(double *n1, double *n2, double *n3);

int main(void)
{
    /* code */
    double n1, n2, n3;
    printf("Enter three numbers: ");
    scanf("%lf %lf %lf", &n1, &n2, &n3);
    printf("n1 = %g, n2 = %g, n3 = %g\n", n1, n2, n3);
    sort_of(&n1, &n2, &n3);
    printf("n1 = %g, n2 = %g, n3 = %g\n", n1, n2, n3);
    return 0;
}

void sort_of(double *n1, double *n2, double *n3)
{
    double max, min, sum;
    sum = *n1 + *n2 + *n3;

    // 找出最大值
    *n1 > *n2 ? (max = *n1) : (max = *n2);
    if (*n3 > max)
    {
        max = *n3;
    }

    // 找出最小值
    *n1 < *n2 ? (min = *n1) : (min = *n2);
    if (*n3 < min)
    {
        min = *n3;
    }

    *n1 = min;
    *n3 = max;
    *n2 = sum - max - min;
}
