/* strptr.c -- 把字符串看作指针 */
#include <stdio.h>
int main(void)
{
    char greeting[50] = "Hello, and"
                        " how are"
                        " you"
                        " today!";
    printf("%s\n", greeting);

    char greeting2[50] = "Hello, and how are you today!";
    printf("%s\n", greeting2);

    printf("%s, %p, %c\n", "We", "are", *"space farers");
    return 0;
}