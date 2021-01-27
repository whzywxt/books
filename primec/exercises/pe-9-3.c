#include <stdio.h>
void chLineRow(char ch, int c, int r);

int main(void)
{
    char ch;
    int col, row;

    printf("Enter a character (# to quit): \n");
    while ((ch = getchar()) != '#')
    {
        if (ch == '\n')
        {
            continue;
        }

        printf("Enter number of columns and number of rows: \n");
        if (scanf("%d %d", &col, &row) != 2)
        {
            break;
        }

        chLineRow(ch, col, row);
        printf("\nEnter next character (# to quit): \n");
    }
    printf("Bye!\n");

    return 0;
}

void chLineRow(char ch, int c, int r)
{
    int col, row;
    for (row = 0; row < r; row++)
    {
        for (col = 0; col < c; col++)
        {
            putchar(ch);
        }
        putchar('\n');
    }
    return;
}