#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // GET DATAS
    int start_size = get_int("Start Size: ");
    while (start_size < 9)
    {
        start_size = get_int("Start Size: ");
    }

    int end_size = get_int("End Size: ");
    while (end_size < start_size)
    {
        end_size = get_int("End Size: ");
    }
    //

    int i = 0;
    int result;
    while (start_size < end_size)
    {
        result = (start_size / 3) - (start_size / 4);
        start_size += result;

        i++;
    }
    printf("Years: %i\n", i);
}