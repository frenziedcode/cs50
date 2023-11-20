#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>

int check_array_Size (string input_Name);
void swap(int* xp, int* yp);
void selectionSort(int array[], int n);

int main(int argc, string argv[])
{
    // Tenta abrir o arquivo
    FILE *archive = fopen(argv[1], "r");

    // Verify if archive was successes opened
    if (archive == NULL)
    {
        fprintf(stderr, "Can´t open the archive.\n");
        return 1;
    }

    // Variable to store numbers
    int num;
    int array_Size;

   array_Size = check_array_Size (argv[1]);
   int array[array_Size];

    int i = 0;
    while (fscanf(archive, "%d", &num) == 1)
    {
        array[i] = num;
        i++;

        if (i >= array_Size)
            break;
    }

    fclose(archive);

    // Selection Sort
    selectionSort(array, array_Size);

    // print numbers
    for (i = 0; i < array_Size; i++)
    {
        printf("%d\n", array[i]);
    }

    printf("\n\n\n"); // DEBUG
    printf("ARGV[1] = %s\n", argv[1]); // DEBUG
    printf("array_Size = %i\n", array_Size); // DEBUG
    printf("Array[0] = %i\n", array[0]); // DEBUG
    printf("Array[%i] = %i\n", array_Size, array[array_Size - 1]); // DEBUG

    printf("\n"); // DEBUG
    return 0;
}

int check_array_Size (string input_Name)
{

    if ( strcmp(input_Name, "random5000.txt") == 0 )
        return 5000;
    else if ( strcmp(input_Name, "random10000.txt") == 0 )
        return 10000;
    else if ( strcmp(input_Name, "random50000.txt") == 0 )
        return 50000;
    else if ( strcmp(input_Name, "reversed5000.txt") == 0 )
        return 5000;
    else if ( strcmp(input_Name, "reversed10000.txt") == 0 )
        return 10000;
    else if ( strcmp(input_Name, "reversed50000.txt") == 0 )
        return 50000;


    return 0;
}

void swap(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void selectionSort(int array[], int n)
{
    int i, j, min_idx;

    for (i = 0; i < n ; i++)
    {
        min_idx = 1;
        for (j = i + 1; j < n; j++)
        {
            if (array[j] < array[min_idx])
                min_idx = j;
        }
        swap(&array[min_idx], &array[i]);
    }
}
