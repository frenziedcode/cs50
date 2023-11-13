// Check that a password has at least one lowercase letter, uppercase letter, number and symbol
// Practice iterating through a string
// Practice using the ctype library

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>

bool valid(string password);

bool valid(string password);

int main(void)
{
    string password = get_string("Enter your password: ");
    if (valid(password))
    {
        printf("Your password is valid!\n");
    }
    else
    {
        printf("Your password needs at least one uppercase letter, lowercase letter, number and symbol\n");
    }
}

// TODO: Complete the Boolean function below
bool valid(string password)
{
    bool isLower = false;
    bool isUpper = false;
    bool isNumber = false;
    bool isSymbol = false;

    int i = 0;
    while (password[i] != 0)
    {
        // Check that a password has at least one lowercase letter
        if (password[i] > 96 && password[i] < 124)
            isLower = true;
        // Check that a password has at least one lowercase upper
        if (password[i] > 64 && password[i] < 91)
            isUpper = true;
        // Check that a password has at least one lowercase number
        if (password[i] > 47 && password[i] < 58)
            isNumber = true;
        // Check that a password has at least one lowercase symbol
        if (password[i] > 32 && password[i] < 48)
            isSymbol = true;
        i++;
    }
    if (isLower == true && isUpper == true && isNumber == true && isSymbol == true)
        return true;

    return false;
}