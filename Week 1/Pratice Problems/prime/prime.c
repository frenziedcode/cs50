#include <cs50.h>
#include <stdio.h>

bool prime(int number);

int main(void)
{
    int min;
    min = get_int("Minimum: ");
    while (min < 1)
    {
        min = get_int("Minimum: ");
    }

    int max;
    max = get_int("Maximum: ");
    while (min >= max)
    {
        max = get_int("Maximum: ");
    }

    for (int i = min; i <= max; i++)
    {
        if (prime(i))
        {
            printf("%i\n", i);
        }
    }
}

bool prime(int number)
{
    // TODO
    if (number == 1 || number == -1 || number == 0)
    {
        return false;
    }

    int i = 2;
    while (i <= number / 2)
    {
        if (number % i == 0)
        {
            return false;
        }
        i++;
    }
    return true;
}