#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);

int main(void)
{
    string input = get_string("Message: ");

    int i = 0;
    while (input[i] != 0)
    {
        int character = input[i];
        int binary[8]; // Array for save 8 binary bits

        for (int j = 7; j >= 0; j--)
        {
            binary[j] = character % 2;
            character /= 2;
        }
        // printf("Character '%c' in binary: ", input[i]);

        for (int j = 0; j < BITS_IN_BYTE; j++)
            print_bulb(binary[j]);
        printf("\n");

        i++;
    }

    return 0;
}

void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}