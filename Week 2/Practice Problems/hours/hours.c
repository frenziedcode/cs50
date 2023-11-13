#include <cs50.h>
#include <ctype.h>
#include <stdio.h>

float calc_hours(int hours[], int weeks, char output);

int main(void)
{
    int weeks = get_int("Number of weeks taking CS50: ");
    int hours[weeks];

    int sumHours = 0;
    for (int i = 0; i < weeks; i++)
    {
        hours[i] = get_int("Week %i HW Hours: ", i);
        sumHours += hours[i];
    }

    char output = '0';
    while (output != 'T' && output != 'A')
    {
        output = toupper(get_char("Enter T for total hours, A for average hours per week: "));
    }

    printf("%.1f hours\n", calc_hours(hours, weeks, output));
}

// TODO: complete the calc_hours function
float calc_hours(int hours[], int weeks, char output)
{
    // Calc 'T'
    int sumHours = 0;
    int i = 0;
    while (i < weeks)
    {
        sumHours += hours[i];
        i++;
    }
    if (output == 'T')
        return (float) sumHours;

    return (float) sumHours / weeks;
}