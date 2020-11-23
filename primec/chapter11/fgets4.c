/* fgets3.c -- 使用 fgets() */
#include <stdio.h>
#define STLEN 10
int main(void)
{
    char words[STLEN];
    puts("Enter strings (empty line to quit):");
    gets_s(words, STLEN);
    puts(words);

    // puts("Enter strings (empty line to quit)2:");
    // gets(words);
    // puts(words);

    puts("done");
    return 0;
}