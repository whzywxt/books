#include <stdio.h>

void copy_arr(double target1[], double s1[], int x)
{
    int i;

    for (i = 0; i < x; i++)
    {
        target1[i] = s1[i];
    }
    return;
}

void copy_ptr(double target2[], double s2[], int y)
{
    double *t_index;
    double *s_index;
    int j;

    t_index = target2;
    s_index = s2;
    for (j = 0; j < y; j++)
    {
        *(t_index + j) = *(s_index + j);
    }

    return;
}

void copy_ptrs(double target3[], double s3[], double *index)
{

    int i = 0;

    while (s3 < index)
    {
        target3[i] = *s3;
        s3++;
        i++;
    }

    return;
}

int main(void)
{
    double source[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
    double target1[5];
    double target2[5];
    double target3[5];

    void copy_arr(double target1[], double s1[], int x);
    void copy_ptr(double target2[], double s2[], int y);
    void copy_ptrs(double target3[], double s3[], double *index);

    copy_arr(target1, source, 5);
    copy_ptr(target2, source, 5);
    copy_ptrs(target3, source, source + 5);
    printf("target 1 :   \n");
    printf("%.1f %.1f %.1f %.1f\n", target1[0], target1[1], target1[2], target1[3]);
    printf("target 2 :   \n");
    printf("%.1f %.1f %.1f %.1f\n", target2[0], target2[1], target2[2], target2[3]);
    printf("target 3 :   \n");
    printf("%.1f %.1f %.1f %.1f\n", target3[0], target3[1], target3[2], target3[3]);

    // system("pause");
    return 0;
}