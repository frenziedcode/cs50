#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height = get_int("Height: ");
    while (height < 1 || height > 8)
    {
        height = get_int("Height: ");
    }

    int i = 1;
    while (i <= height)
    {
        int space = 1;
        while (space <= height - i)
        {
            printf(" ");
            space++;
        }

        int j = 1;
        while (j <= i)
        {
            printf("#");
            j++;
        }
        printf("\n");
        ++i;
    }
}