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
        int a = 1;
        while (a <= height - i)
        {
            printf(" ");
            ++a;
        }

        int j = 1;
        while (j <= i)
        {
            printf("#");
            j++;
        }

        printf("  ");
        int invert = 1;
        while (invert <= i)
        {
            printf("#");
            invert++;
        }

        printf("\n");
        i++;
    }
}