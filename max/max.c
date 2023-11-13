// Practice writing a function to find a max value

#include <cs50.h>
#include <stdio.h>

int max(int array[], int n);

int main(void)
{
    // Verify if number of the elements is great than 1
    int n;
    do
    {
        n = get_int("Number of elements: ");
    }
    while (n < 1);

    // Store the value inside Array
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = get_int("Element %i: ", i);
    }

    // Compare values
    printf("The max value is %i.\n", max(arr, n));
}

// TODO: return the max value
int max(int array[], int n)
{
    int tmp[1];
    int max_index;

    for (int i = 0; i < n; i++)
    {
        max_index = i;
        for (int j = i + 1; j < n; j++)
        {
            if (array[j] >= array[max_index])
                max_index = j;
        }
        tmp[0] = array[i];
        array[i] = array[max_index];
        array[max_index] = tmp[0];
    }
    return array[0];
}
