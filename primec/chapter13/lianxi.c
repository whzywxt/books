#include <stdio.h>

int main(void)
{
    // int *fp;
    // int k;
    // fp = fopen("gelatin");
    // for (k = 0; k < 30; k++)
    //     fputs(fp, "Nanette eats gelatin.");
    // fclose("gelatin");
    // return 0;

    FILE *fp;
    int k;
    char str[80];
    fp = fopen("gelatin", "w");
    for (k = 0; k < 30; k++)
    {
        sprintf(str, "%2d Nanette eats gelatin.\n", k + 1);
        fputs(str, fp);
    }
    fclose(fp);
    return 0;
}