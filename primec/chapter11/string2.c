#include <stdio.h>

int main(void)
{
    char *p1 = "Klingon";
    // p1[0] = 'F'; // ok? bad
    printf("Klingon");

    printf(": Beware the %ss!\n", "Klingon");

    return 0;
}
