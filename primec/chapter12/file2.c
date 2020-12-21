#include <stdio.h>
extern const double PI;
extern const char *MONTHS[12];

int main(int argc, char const *argv[])
{
    int i;
    printf("%f\n", PI);
    for (i = 0; i < 12; i++)
    {
        printf("%s ", MONTHS[i]);
    }

    return 0;
}