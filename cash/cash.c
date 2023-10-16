#include <cs50.h>
#include <stdio.h>

int get_cents(void);
int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

int main(void)
{
    // Ask how many cents the customer is owed
    int cents = get_cents();

    // Calculate the number of quarters to give the customer
    int quarters = calculate_quarters(cents);
    cents = cents - quarters * 25;

    // Calculate the number of dimes to give the customer
    int dimes = calculate_dimes(cents);
    cents = cents - dimes * 10;

    // Calculate the number of nickels to give the customer
    int nickels = calculate_nickels(cents);
    cents = cents - nickels * 5;

    // Calculate the number of pennies to give the customer
    int pennies = calculate_pennies(cents);
    cents = cents - pennies * 1;

    // Sum coins
    int coins = quarters + dimes + nickels + pennies;

    // Print total number of coins to give the customer
    printf("%i\n", coins);
    // printf("Quarters: %i + Dimes: %i + Nickels: %i + Pennies: %i\n", quarters, dimes, nickels, pennies);
}

int get_cents(void)
{
    int cents = get_int("Change owed: ");
    while (cents < 1)
    {
        cents = get_int("Change owed: ");
    }
    return cents;
}

int calculate_quarters(int cents)
{
    int i = 0;
    int quarters = 25;

    if (cents >= 25)
    {
        i = 1;
        while ((cents - quarters != 0) && (cents - quarters >= 25))
        {
            cents -= quarters;
            i++;
        }
    }
    return i;
}

int calculate_dimes(int cents)
{
    int i = 0;
    int dimes = 10;

    calculate_quarters(cents);
    if (cents >= 10)
    {
        i = 1;
        while ((cents - dimes != 0) && (cents - dimes) >= 10)
        {
            cents -= dimes;
            i++;
        }
    }

    return i;
}

int calculate_nickels(int cents)
{
    int i = 0;
    int nickels = 5;

    calculate_dimes(cents);
    if (cents >= 5)
    {
        i = 1;
        while ((cents - nickels != 0) && (cents - nickels) >= 5)
        {
            cents -= nickels;
            i++;
        }
    }

    return i;
}

int calculate_pennies(int cents)
{
    int i = 0;
    int pennies = 1;

    calculate_nickels(cents);
    if (cents < 5 && cents >= 1)
    {
        i = 1;
        while ((cents - pennies != 0) && (cents - pennies) < 5 && (cents - pennies) >= 1)
        {
            cents -= pennies;
            i++;
        }
    }

    return i;
}
